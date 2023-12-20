using System.Collections;

namespace OrganizationsLibrary;

public interface IInit
{
    void Init();
    void RandomInit();
}

public class SortByEmployeesCount : IComparer
{
    int IComparer.Compare(object? obj1, object? obj2)
    {
        if (obj1 is null || obj2 is null) return 1;

        Organization org1 = (Organization)obj1;
        Organization org2 = (Organization)obj2;

        if (org1.EmployeesCount > org2.EmployeesCount) return 1;
        if (org1.EmployeesCount < org2.EmployeesCount) return -1;
        return 0;
    }
}
