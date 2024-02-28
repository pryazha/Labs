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
        }
    </style>
</head>
    <body style="text-align: center">

        <form method="post">
            <input type="submit" name="fTask" value="Получить список сотрудников, номера телефонов и ЗП"/>
            <input type="submit" name="sTask" value="Получить список сотрудников с их адресами"/>
            <input type="submit" name="tTask" value="Получить список сотрудников с продолжительностью трудовой деятельности больше 4"/>
            <input type="submit" name="print" value="Вывести всю таблицу"/>
        </form>

        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "прядеин";

        function first_task() {
            global $servername, $username, $password, $dbname;
            $conn = new mysqli($servername, $username, $password, $dbname);

            if ($conn->connect_error) {
                die("Connection failed: " . $conn->connect_error);
            }

            $sql = "SELECT lastname, phone, salary FROM table_прядеин";
            $result = $conn->query($sql);

            if ($result->num_rows > 0) {
                echo "<table class='center'><tr>
                    <th>Фамилия</th>
                    <th>Телефон</th>
                    <th>Зарплата</th></tr>";
                // output data of each row
                while($row = $result->fetch_assoc()) {
                    echo "<tr><td>".$row["lastname"].
                        "</td><td>".$row["phone"].
                        "</td><td>".$row["salary"]."</td></tr>";
                }
                echo "</table>";
            } else {
                echo "0 results";
            }

            $conn->close();
        }

        function second_task() {
            global $servername, $username, $password, $dbname;
            $conn = new mysqli($servername, $username, $password, $dbname);

            if ($conn->connect_error) {
                die("Connection failed: " . $conn->connect_error);
            }
            $sql = "SELECT lastname, adress FROM table_прядеин ORDER BY adress";
            $result = $conn->query($sql);

            if ($result->num_rows > 0) {
                echo "<table class='center'><tr>
                    <th>Фамилия</th>
                    <th>Адрес</th></tr>";
                // output data of each row
                while($row = $result->fetch_assoc()) {
                    echo "<tr><td>".$row["lastname"].
                        "</td><td>".$row["adress"]."</td></tr>";
                }
                echo "</table>";
            } else {
                echo "0 results";
            }

            $conn->close();
        }

        function third_task() {
            global $servername, $username, $password, $dbname;
            $conn = new mysqli($servername, $username, $password, $dbname);

            if ($conn->connect_error) {
                die("Connection failed: " . $conn->connect_error);
            }

            $sql = "SELECT lastname, employment_day,
                    TIMESTAMPDIFF(YEAR, employment_day, CURRENT_DATE()) as 'work_experience'
                    FROM table_прядеин
                    WHERE TIMESTAMPDIFF(YEAR, employment_day, CURRENT_DATE()) > 4";
            $result = $conn->query($sql);

            if ($result->num_rows > 0) {
                echo "<table class='center'><tr>
                    <th>Фамилия</th>
                    <th>Дата найма</th>
                    <th>Трудовой стаж</th></tr>";
                // output data of each row
                while($row = $result->fetch_assoc()) {
                    echo "<tr><td>".$row["lastname"].
                        "</td><td>". $row["employment_day"].
                        "</td><td>".$row["work_experience"]."</td></tr>";
                }
                echo "</table>";
            } else {
                echo "0 results";
            }

            $conn->close();
        }

        function print_table() {
            global $servername, $username, $password, $dbname;
            $conn = new mysqli($servername, $username, $password, $dbname);

            if ($conn->connect_error) {
                die("Connection failed: " . $conn->connect_error);
            }

            $sql = "SELECT * FROM table_прядеин";
            $result = $conn->query($sql);

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
                // output data of each row
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
                echo "0 results";
            }

            $conn->close();
        }

        if (isset($_POST['fTask'])) {
            first_task();
        }
        if (isset($_POST['sTask'])) {
            second_task();
        }
        if (isset($_POST['tTask'])) {
            third_task();
        }
        if (isset($_POST['print'])) {
            print_table();
        }
        ?>

    </body>
</html>

