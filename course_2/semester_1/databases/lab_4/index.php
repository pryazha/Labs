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
        Команды DDL
        <form method="post">
            <input type="submit" name="createTable" value="Создать таблицу"/>
            <input type="submit" name="createIndex" value="Создать индекс"/>
            <input type="submit" name="createView" value="Создать представление"/>
            <input type="submit" name="dropTable" value="Удалить таблицу"/>
            <input type="submit" name="truncateTable" value="Очистить таблицу"/>
        </form><p></p>

        Команды DML
        <form method="post">
            <input type="submit" name="insert" value="Добавить записи"/>
            <input type="submit" name="alter" value="Добавить столбец места работы"/>
            <input type="submit" name="update" value="Обновить запись с id = 1"/>
            <input type="submit" name="print" value="Вывести таблицу"/>
        </form>

        <form method="post">
            <input type="submit" name="innerJoin" value="Внутреннее соединение (INNER JOIN)"/>
        </form>


        <?php
        function CreateTable($mysqli) {
            $sql = "CREATE TABLE employees (
                id INT AUTO_INCREMENT,
                lastname VARCHAR(20),
                firstname VARCHAR(20),
                patronymic VARCHAR(20),
                phone VARCHAR(11),
                employment_day DATE,
                salary INT,
                adress VARCHAR(100),
                PRIMARY KEY(id))";
            $mysqli->query($sql);
            echo "Table created successfully";
        }

        function CreateIndex($mysqli) {
            $sql = "CREATE INDEX lastname_firstname_idx
                ON employees(lastname, firstname)";
            $mysqli->query($sql);
            echo "Index created successfully"; 
        }

        function CreateView($mysqli) {
            $sql = "CREATE OR REPLACE VIEW View AS
                    SELECT lastname, salary
                    FROM employees WHERE salary > 70000";
            $mysqli->query($sql);

            $result = $mysqli->query("SELECT * FROM View");
            if ($result->num_rows > 0) {
                echo "<table class='center'><tr>
                    <th>Фамилия</th>
                    <th>Заработная плата</th></tr>";
                while($row = $result->fetch_assoc()) {
                    echo "<tr><td>".$row["lastname"].
                        "</td><td>".$row["salary"]."</td></tr>";
                }
                echo "</table>";
            } else {
                echo "View is empty";
            }
        }

        function DropTable($mysqli) {
            $mysqli->query("DROP TABLE employees");
            echo "Table delete successfully";
        }

        function TruncateTable($mysqli) {
            if ($mysqli->query("SHOW COLUMNS FROM employees LIKE 'department_id'")->num_rows > 0) {
                $mysqli->query("ALTER TABLE employees DROP COLUMN department_id");
            }
            $mysqli->query("TRUNCATE TABLE employees");
            PrintTable($mysqli);
        }

        function InsertValues($mysqli) {
            $sql = 'INSERT INTO employees(lastname, firstname, patronymic, phone, employment_day, salary, adress)
                VALUES
                ("Прядеин", "Иван", "Алексеевич", "89824454932", "2005-08-26", 100000, "г.Пермь, ул.Дедюкина, 20"),	
                ("Коротков", "Павел", "Маркович", "89828495561", "2021-04-11", 85750, "г.Рязань, ул.Солнечная, 3"),
                ("Игнатьева", "Ева", "Александровна", "89825682933", "2007-02-15", 98052, "г.Псков, ул.3 Марта, 14"),
                ("Сухов", "Никита", "Богданович", "89822694053", "2004-07-04", 65042, "г.Боровичи, ул.Солнечная, 12"),
                ("Орехова", "Ксения", "Львовна", "89824576627", "2018-02-14", 66771, "г.Волгодонск, ул.Новая, 18"),
                ("Колесникова", "Надежда", "Михайловна", "89827613328", "2009-05-08", 73295, "г.Саратов, ул.3 Марта, 4"),
                ("Новиков", "Михаил", "Алексеевич", "89828618040", "2011-08-18", 88413, "г.Киров, ул.Октябрьская, 6"),
                ("Лосев", "Максим", "Даниилович", "89820061601", "2003-08-31", 36079, "г.Магадан, ул.Тихая, 19"),
                ("Иванова", "Малика", "Кирилловна", "89826873149", "2008-08-07", 43494, "г.Волгодонск, ул.Школьная, 11"),
                ("Волков", "Глеб", "Александрович", "89821014293", "2007-12-28", 92460, "г.Курган, ул.Комсомольская, 24"),
                ("Ульянова", "Алиса", "Адамовна", "89822743265", "2010-04-23", 72043, "г.Боровичи, ул.Калинина, 12"),
                ("Попова", "Арина", "Петровна", "89821627638", "2017-05-11", 44320, "г.Киров, ул.Солнечная, 1"),
                ("Сазонова", "Полина", "Павловна", "89826496909", "2006-12-04", 67256, "г.Псков, ул.Октябрьская, 3"),
                ("Сомов", "Макар", "Михайлович", "89825367398", "2018-03-07", 72919, "г.Балашиха, ул.Строителей, 12"),
                ("Кулаков", "Тимур", "Артёмович", "89822901541", "2001-02-07", 76944, "г.Псков, ул.Комсомольская, 20"),
                ("Матвеева", "Полина", "Всеволодовна", "89829252242", "2007-10-22", 87889, "г.Ижевск, ул.Дружная, 3"),
                ("Блинова", "Дарья", "Данииловна", "89821653051", "2006-04-23", 80067, "г.Балашиха, ул.Новая, 21"),
                ("Громов", "Андрей", "Кириллович", "89821627638", "2023-05-12", 99284, "г.Саратов, ул.Школьная, 17"),
                ("Романова", "Мила", "Александровна", "89820061601", "2002-05-20", 97022, "г.Киров, ул.Тихая, 1"),
                ("Токарева", "Милана", "Тимофеевна", "89822579961", "2022-11-18", 62532, "г.Магадан, ул.Строителей, 17")';
            $mysqli->query($sql);
            PrintTable($mysqli);
        }

        function AlterTable($mysqli) {
            if (!$mysqli->query("SHOW COLUMNS FROM employees LIKE 'department_id'")->num_rows > 0 && 
                $mysqli->query("SELECT * FROM employees")->num_rows > 0)
            {
                $mysqli->query("ALTER TABLE employees ADD department_id INT");
            }
            $mysqli->query("UPDATE employees SET department_id = 1 + FLOOR(RAND() * 3)");
            PrintTable($mysqli);
        }

        function UpdateValue($mysqli) {
            $mysqli->query("UPDATE employees
                            SET lastname = 'Иванов', firstname = 'Иван', patronymic = 'Иванович', phone = '89999999999', salary = '100000', adress = 'г.Пермь'
                            WHERE id = 1");
            PrintTable($mysqli);
        }

        function PrintTable($mysqli) {
            $result = $mysqli->query("SELECT * FROM employees");

            if ($result->num_rows > 0) {
                if ($mysqli->query("SHOW COLUMNS FROM employees LIKE 'department_id'")->num_rows > 0) {
                    echo "<table class='center'><tr>
                        <th>Id</th>
                        <th>Фамилия</th>
                        <th>Имя</th>
                        <th>Отчество</th>
                        <th>Номер телефона</th>
                        <th>Дата найма</th>
                        <th>Заработная плата</th>
                        <th>Адрес</th>
                        <th>id отдела</th></tr>";
                    while($row = $result->fetch_assoc()) {
                        echo "<tr><td>".$row["id"].
                            "</td><td>".$row["lastname"].
                            "</td><td>".$row["firstname"].
                            "</td><td>".$row["patronymic"].
                            "</td><td>".$row["phone"].
                            "</td><td>".$row["employment_day"].
                            "</td><td>".$row["salary"].
                            "</td><td>".$row["adress"].
                            "</td><td>".$row["department_id"]."</td></tr>";
                    }
                    echo "</table>";
                } else {
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
                }
            } else {
                echo "Table is empty";
            }
        }

        function InnerJoin($mysqli) {
            if ($mysqli->query("SELECT department_id FROM employees")->num_rows > 0) {
                PrintTable($mysqli);

                $result = $mysqli->query("SELECT * FROM departments");
                if ($result->num_rows > 0) {
                    echo "<table class='center'><tr>
                        <th>Id</th>
                        <th>Название отдела</th></tr>";
                    while ($row = $result->fetch_assoc()) {
                        echo "<tr><td>".$row["department_id"].
                            "</td><td>".$row["department_name"]."</td></tr>";
                    }
                    echo "</table>";
                } else {
                    echo "Table 'departments' is empty";
                }

                $sql = "SELECT lastname, firstname, department_name
                    FROM employees INNER JOIN departments
                    ON departments.department_id = employees.department_id";
                $result = $mysqli->query($sql);
                if ($result->num_rows > 0) {
                    echo "<table class='center'><tr>
                        <th>Фамилия</th>
                        <th>Имя</th>
                        <th>Название отдела</th></tr>";
                    while ($row = $result->fetch_assoc()) {
                        echo "<tr><td>".$row["lastname"].
                            "</td><td>".$row["firstname"].
                            "</td><td>".$row["department_name"]."</td></tr>";
                    }
                    echo "</table>";
                } else {
                    echo "Table is empty";
                }
            } else {
                echo "Error: Table employees does not contain department_id column";
            }
        }

        $mysqli = new mysqli("localhost", "root", "", "прядеин");
        if ($mysqli->connect_error) {
            die("Connection failed: " . $mysqli->connect_error);
        }

        if (isset($_POST['createTable'])) {
            try {
            CreateTable($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }
        
        if (isset($_POST['createIndex'])) {
            try {
                CreateIndex($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }

        if (isset($_POST['createView'])) {
            try {
                CreateView($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }

        if (isset($_POST['dropTable'])) {
            try {
                DropTable($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }

        if (isset($_POST['truncateTable'])) {
            try {
                TruncateTable($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }

        if (isset($_POST['insert'])) {
            try {
                InsertValues($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }
        
        if (isset($_POST['alter'])) {
            try {
                AlterTable($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }

        if (isset($_POST['update'])) {
            try {
                UpdateValue($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }

        if (isset($_POST['print'])) {
            try {
                PrintTable($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }

        if (isset($_POST['innerJoin'])) {
            try {
                InnerJoin($mysqli);
            } catch (Exception $e) {
                echo "Error: " . $e->getMessage();
            }
        }
        ?>
    </body>
</html>
