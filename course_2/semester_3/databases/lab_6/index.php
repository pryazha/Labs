<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <style>
        table, td, th {
            border: 1px solid black;
            border-collapse: collapse;
            text-align: center
        }
        td, th {
            padding: 5px;
        }
        table.center {
            margin-top: 100px;
            margin-left: auto;
            margin-right: auto;
            margin-bottom: auto;
        }
        input[type=submit] {
            padding: 5px;
            margin-left: 10px;
            margin-right: 10px;
            margin-top: 20px;
            margin-bottom: 20px;
        }
    </style>
</head>
    <body style="text-align: center">
        <form method="post">
            <input type="submit" name="printTable" value="Вывести таблицу"/>
            <input type="submit" name="insertRow" value="Добавить запись"/>
            <input type="submit" name="updateLastRow" value="Изменить последнюю запись"/>
            <input type="submit" name="deleteLastRow" value="Удалить последнюю запись"/>
            <input type="submit" name="truncateTableLog" value="Очистить таблицу 'log'"/>
        </form>

        <?php
        function PrintTable($mysqli) {
            $result = $mysqli->query("SELECT * FROM table_прядеин");

            if ($result->num_rows > 0) {
                echo "<table class='center'><tr>
                    <th>Id</th>
                    <th>Фамилия</th>
                    <th>Имя</th>
                    <th>Отчество</th>
                    <th>Номер телефона</th>
                    <th>Дата найма</th>
                    <th>Заработная плата</th>
                    <th>Адрес</th></tr>";
                while($row = $result->fetch_assoc()) {
                    echo "<tr><td>".$row["id"].
                        "</td><td>".$row["lastname"].
                        "</td><td>".$row["firstname"].
                        "</td><td>".$row["patronymic"].
                        "</td><td>".$row["phone"].
                        "</td><td>".$row["employment_day"].
                        "</td><td>".$row["salary"].
                        "</td><td>".$row["adress"]."</td></tr>";
                }
                echo "</table>";
            } else {
                echo "Table 'table_прядеин' is empty";
            }

            $result = $mysqli->query("SELECT * FROM log");

            if ($result->num_rows > 0) {
                echo "<table class='center'><tr>
                    <th>Id</th>
                    <th>Id сотрудника</th>
                    <th>Предыдущая фамилия</th>
                    <th>Новая фамилия</th>
                    <th>Предыдущее имя</th>
                    <th>Новое имя</th>
                    <th>Предыдущее отчество</th>
                    <th>Новое отчество</th>
                    <th>Тип изменения</th>
                    <th>Дата измененеия</th></tr>";
                while($row = $result->fetch_assoc()) {
                    echo "<tr><td>".$row["id"].
                        "</td><td>".$row["data_id"].
                        "</td><td>".$row["old_lastname"].
                        "</td><td>".$row["new_lastname"].
                        "</td><td>".$row["old_firstname"].
                        "</td><td>".$row["new_firstname"].
                        "</td><td>".$row["old_patronymic"].
                        "</td><td>".$row["new_patronymic"].
                        "</td><td>".$row["change_type"].
                        "</td><td>".$row["change_time"]."</td></tr>";
                }
                echo "</table>";
            } else {
                echo "</p>Table 'log' is empty";
            }
        }

        function InsertRow($mysqli) {
            $last_names = array("Попов", "Головин", "Филиппов", "Ермаков", "Гаврилов");
            $first_names = array("Эмир", "Тимофей", "Матвей", "Дмитрий", "Марк");
            $patronymics = array("Кириллович", "Андреевич", "Степанович", "Демидович", "Александрович");
            $adresses = array("г.Пермь", "г.Ижевск", "г.Киров", "г.Саратов", "г.Рязань");

            $sql = "INSERT INTO table_прядеин(lastname, firstname, patronymic, phone, employment_day, salary, adress)
                VALUES (?,?,?,?,?,?,?)";

            $last_name = $last_names[rand(0, count($last_names) - 1)];
            $first_name = $first_names[rand(0, count($first_names) - 1)];
            $patronymic = $patronymics[rand(0, count($patronymics) - 1)];
            $phone = "89991234567";
            $current_date = date("Y-m-d");
            $salary = rand(30000, 100000);
            $adress = $adresses[rand(0, count($adresses) - 1)];

            $stmt = $mysqli->prepare($sql);
            $stmt->bind_param("sssssis", $last_name, $first_name, $patronymic, $phone, $current_date, $salary, $adress);
            $stmt->execute();
            PrintTable($mysqli);
        }

        function UpdateLastRow($mysqli) {
            $last_names = array("Попов", "Головин", "Филиппов", "Ермаков", "Гаврилов");
            $first_names = array("Эмир", "Тимофей", "Матвей", "Дмитрий", "Марк");
            $patronymics = array("Кириллович", "Андреевич", "Степанович", "Демидович", "Александрович");

            $last_name = $last_names[rand(0, count($last_names) - 1)];
            $first_name = $first_names[rand(0, count($first_names) - 1)];
            $patronymic = $patronymics[rand(0, count($patronymics) - 1)];

            if ($mysqli->query("SELECT * FROM table_прядеин")->num_rows > 0) {
                $stmt = $mysqli->prepare("UPDATE table_прядеин
                                SET lastname = ?, firstname = ?, patronymic = ?
                                ORDER BY id DESC LIMIT 1");
                $stmt->bind_param("sss", $last_name, $first_name, $patronymic);
                $stmt->execute();
                PrintTable($mysqli);
            } else {
                echo "Table is empty";
            }
        }

        function DeleteLastRow($mysqli) {
            if ($mysqli->query("SELECT * FROM table_прядеин")->num_rows > 0) {
                $mysqli->query("DELETE FROM table_прядеин ORDER BY id DESC LIMIT 1");
                PrintTable($mysqli);
            } else {
                echo "Table is empty";
            }
        }

        function TruncateTableLog($mysqli) {
            if ($mysqli->query("SELECT * FROM log")->num_rows > 0) {
                $mysqli->query("TRUNCATE TABLE log");
            }
            PrintTable($mysqli);
        }

        $mysqli = new mysqli("localhost", "root", "", "прядеин");
        if ($mysqli->connect_error) {
            die("Connection failed: " . $mysqli->connect_error);
        }

        if (isset($_POST['printTable'])) {
            try {
                PrintTable($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }

        if (isset($_POST['insertRow'])) {
            try {
                InsertRow($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }

        if (isset($_POST['updateLastRow'])) {
            try {
                UpdateLastRow($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }

        if (isset($_POST['deleteLastRow'])) {
            try {
                DeleteLastRow($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }
        
        if (isset($_POST['truncateTableLog'])) {
            try {
                TruncateTableLog($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }
        ?>
    </body>
</html>
