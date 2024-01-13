using OrganizationsLibrary;

namespace OrganizationsLibraryTests;

public class OrganizationTests
{
    [Fact]
    public void Organization_Equals_SameOrganization_ReturnsTrue()
    {
        // Arrange
        var org1 = new Organization("OrgName", "OrgAddress", 100);
        var org2 = new Organization("OrgName", "OrgAddress", 100);

        // Act

        // Assert
        Assert.True(org1.Equals(org2));
    }

    [Fact]
    public void Organization_Equals_DifferentOrganization_ReturnsFalse()
    {
        // Arrange
        var org1 = new Organization("OrgName1", "OrgAddress1", 100);
        var org2 = new Organization("OrgName2", "OrgAddress2", 200);

        // Act

        // Assert
        Assert.False(org1.Equals(org2));
    }

    [Fact]
    public void Organization_Equals_NullObject_ReturnsFalse()
    {
        // Arrange
        var org1 = new Organization("OrgNam1", "OrgAddress1", 100);
        
        // Act
        bool result = org1.Equals(null);

        // Assert
        Assert.False(result);
    }

    [Fact]
    public void Organization_Equals_NullObjectWhileCasting_ReturnsFalse()
    {
        // Arrange
        var org1 = new Organization("OrgNam1", "OrgAddress1", 100);
        string org2 = "Just a string";
        
        // Act
        bool result = org1.Equals(org2);

        // Assert
        Assert.False(result);
    }

    [Fact]
    public void Organization_EmployeesCount_SetZeroWhenEmployeesCountNegative()
    {
        // Arrange
        var org = new Organization();
        org.EmployeesCount = -100;

        // Act

        // Assert
        Assert.Equal(0, org.EmployeesCount);
    }

    [Fact]
    public void Organization_GetHashCode_SameOrganization_ReturnsSameHashCode()
    {
        // Arrange
        var org1 = new Organization("OrgName", "OrgAddress", 100);
        var org2 = new Organization("OrgName", "OrgAddress", 100);

        // Act

        // Assert
        Assert.Equal(org1.GetHashCode(), org2.GetHashCode());
    }

    [Fact]
    public void Organization_CompareTo_LessThan_ReturnsNegative()
    {
        // Arrange
        var org1 = new Organization("OrgName1", "OrgAddress1", 100);
        var org2 = new Organization("OrgName2", "OrgAddress2", 200);

        // Act
        int result = org1.CompareTo(org2);

        // Assert
        Assert.True(result < 0);
    }

    [Fact]
    public void Organization_CompareTo_GreaterThan_ReturnsPositive()
    {
        // Arrange
        var org1 = new Organization("OrgName2", "OrgAddress2", 200);
        var org2 = new Organization("OrgName1", "OrgAddress1", 100);

        // Act
        int result = org1.CompareTo(org2);

        // Assert
        Assert.True(result > 0);
    }

    [Fact]
    public void Organization_CompareTo_GreaterThanEmployeesCount_ReturnsPositive()
    {
        // Arrange
        var org1 = new Organization("OrgName", "OrgAddress", 200);
        var org2 = new Organization("OrgName", "OrgAddress", 100);

        // Act
        int result = org1.CompareTo(org2);

        // Assert
        Assert.True(result > 0);
    }

    [Fact]
    public void Organization_CompareTo_LessThanEmployeesCount_ReturnsNegative()
    {
        // Arrange
        var org1 = new Organization("OrgName", "OrgAddress", 100);
        var org2 = new Organization("OrgName", "OrgAddress", 200);

        // Act
        int result = org1.CompareTo(org2);

        // Assert
        Assert.True(result < 0);
    }

    [Fact]
    public void Organization_CompareTo_Equal_ReturnsZero()
    {
        // Arrange
        var org1 = new Organization("OrgName", "OrgAddress", 100);
        var org2 = new Organization("OrgName", "OrgAddress", 100);

        // Act
        int result = org1.CompareTo(org2);

        // Assert
        Assert.Equal(0, result);
    }

    [Fact]
    public void Organization_CompareTo_ObjIsNull_ReturnsPositive()
    {
        // Arrange
        var org = new Organization("OrgName", "OrgAddress", 100);

        // Act
        int result = org.CompareTo(null);

        // Assert
        Assert.True(result > 0);
    }

    [Fact]
    public void Organization_ShallowCopy_ReturnsEqualButNotSameInstance()
    {
        // Arrange
        var org1 = new Organization("OrgName", "OrgAddress", 100);
        org1.manager = new Manager("ManagerName");

        // Act
        var org2 = org1.ShallowCopy();

        // Assert
        Assert.Equal(org1, org2);
        Assert.NotSame(org1, org2);
        Assert.Same(org1.manager, org2.manager);
    }

    [Fact]
    public void Organization_Clone_ReturnsEqualButNotSameInstanceWithClonedManager()
    {
        // Arrange
        var org1 = new Organization("OrgName", "OrgAddress", 100);
        org1.manager = new Manager("ManagerName");

        // Act
        var org2 = (Organization)org1.Clone();

        // Assert
        Assert.Equal(org1, org2);
        Assert.NotSame(org1, org2);
        Assert.Equal(org1.manager.Name, org2.manager.Name);
        Assert.NotSame(org1.manager, org2.manager);
    }
}
