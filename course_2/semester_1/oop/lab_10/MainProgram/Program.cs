using OrganizationsLibrary;

namespace lab_10
{
    public class Program
    {
        static void Main()
        {
            Organization org = new Organization();
            org.Show();
            org.Init();
            org.Show();
            org.RandomInit();
            org.Show();
        }
    }
}
