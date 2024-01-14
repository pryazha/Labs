using InputLibrary;

namespace MainProgram;

class Program
{
    static void Main()
    {
        String[] menu = new String[] {
            "Добавить объект.",
            "Удалить объект.",
            "Вывести все объекты типа Library.",
            "Подсчитать количество объектов типа ShipbuildingCompany.",
            "Вывести все объекты типа Organization."
        };

        int choose;
        do
        {
            PrintMenu(menu);
            choose = Input.IntInput("> ");
            switch (choose)
            {
                case 1:
                    
                    break;

                default:
                    Console.WriteLine("Такого выбора не существует");
                    break;
            }
        } while (choose != 0);
    }

    static void PrintMenu(String[] menu)
    {
        for (int i = 0; i < menu.Length; i++)
            Console.WriteLine($"{i + 1}. {menu[i]}");
        Console.WriteLine("0. Выход");
    }
}
