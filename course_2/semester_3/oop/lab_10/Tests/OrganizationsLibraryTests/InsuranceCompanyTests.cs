using OrganizationsLibrary;

namespace OrganizationsLibraryTests;

public class InsuranceCompanyTests
{
    [Fact]
    public void InsuranceCompany_ShallowCopy_ReturnsEqualButNotSameInstance()
    {
        // Arrange
        var insComp1 = new InsuranceCompany();
        insComp1.manager = new Manager("ManagerName");

        // Act
        var insComp2 = insComp1.ShallowCopy();

        // Assert
        Assert.Equal(insComp1, insComp2);
        Assert.Equal(insComp1.InsuranceType, insComp2.InsuranceType);
        Assert.NotSame(insComp1, insComp2);
        Assert.Same(insComp1.manager, insComp2.manager);
    }

    [Fact]
    public void InsuranceCompany_Clone_ReturnsEqualButNotSameInstanceWithClonedManager()
    {
        // Arrange
        var insComp1 = new InsuranceCompany("FactoryName", "FactoryAddress", 100, "InsType");
        insComp1.manager = new Manager("ManagerName");

        // Act
        var insComp2 = (InsuranceCompany)insComp1.Clone();

        // Assert
        Assert.Equal(insComp1, insComp2);
        Assert.NotSame(insComp1, insComp2);
        Assert.Equal(insComp1.InsuranceType, insComp2.InsuranceType);
        Assert.Equal(insComp1.manager.Name, insComp2.manager.Name);
        Assert.NotSame(insComp1.manager, insComp2.manager);
    }
}
