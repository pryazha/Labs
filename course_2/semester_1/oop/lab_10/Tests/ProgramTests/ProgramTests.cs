using lab_10;
using OrganizationsLibrary;

namespace ProgramTests;

public class ProgramTestsClass
{
    [Fact]
    public void Program_MaxEmployeesOrg_ReturnsNullWhenOrganizationsIsNull()
    {
        // Arrange

        // Act
        Organization? result = Program.MaxEmployeesOrg(null);

        // Assert
        Assert.Null(result);
    }

    [Fact]
    public void Program_MaxEmployeesOrg_ReturnsNullWhenOrganizationsLengthIsZero()
    {
        // Arrange
        Organization[] organizations = new Organization[0];

        // Act
        Organization? result = Program.MaxEmployeesOrg(organizations);

        // Assert
        Assert.Null(result);
    }
    
    [Fact]
    public void Program_MaxEmployeesOrg_ReturnsMaxWhenSeveralObjects()
    {
        // Arrange
        Organization[] organizations = new Organization[3];
        organizations[0] = new Organization("OrgName1", "OrgAddress1", 100);
        organizations[1] = new Organization("OrgName2", "OrgAddress2", 200);
        organizations[2] = new Organization("OrgName3", "OrgAddress3", 300);

        Organization expected = new Organization("OrgName3", "OrgAddress3", 300);

        // Act
        Organization? result = Program.MaxEmployeesOrg(organizations);

        // Assert
        Assert.Equal(expected, result);
    }

    [Fact]
    public void Program_MaxEmployeesOrg_ReturnsOnlyObject()
    {
        // Arrange
        Organization[] organizations = new Organization[1];
        organizations[0] = new Organization("OrgName", "OrgAddress", 100);

        Organization expected = new Organization("OrgName", "OrgAddress", 100);

        // Act
        Organization? result = Program.MaxEmployeesOrg(organizations);

        // Assert
        Assert.Equal(expected, result);
    }

    [Fact]
    public void Program_MinEmployeesOrg_ReturnsNullWhenOrganizationsIsNull()
    {
        // Arrange

        // Act
        Organization? result = Program.MinEmployeesOrg(null);

        // Assert
        Assert.Null(result);
    }

    [Fact]
    public void Program_MinEmployeesOrg_ReturnsNullWhenOrganizationsLengthIsZero()
    {
        // Arrange
        Organization[] organizations = new Organization[0];

        // Act
        Organization? result = Program.MinEmployeesOrg(organizations);

        // Assert
        Assert.Null(result);
    }
    
    [Fact]
    public void Program_MinEmployeesOrg_ReturnsMaxWhenSeveralObjects()
    {
        // Arrange
        Organization[] organizations = new Organization[3];
        organizations[0] = new Organization("OrgName1", "OrgAddress1", 100);
        organizations[1] = new Organization("OrgName2", "OrgAddress2", 200);
        organizations[2] = new Organization("OrgName3", "OrgAddress3", 300);

        Organization expected = new Organization("OrgName1", "OrgAddress1", 100);

        // Act
        Organization? result = Program.MinEmployeesOrg(organizations);

        // Assert
        Assert.Equal(expected, result);
    }

    [Fact]
    public void Program_MinEmployeesOrg_ReturnsOnlyObject()
    {
        // Arrange
        Organization[] organizations = new Organization[1];
        organizations[0] = new Organization("OrgName", "OrgAddress", 100);

        Organization expected = new Organization("OrgName", "OrgAddress", 100);

        // Act
        Organization? result = Program.MaxEmployeesOrg(organizations);

        // Assert
        Assert.Equal(expected, result);
    }

    [Fact]
    public void Program_GetBooksCount_ReturnsZeroWhenOrganizationsIsNull()
    {
        // Arrange

        // Act
        int result = Program.GetBooksCount(null);

        // Assert
        Assert.Equal(0, result);
    }

    [Fact]
    public void Program_GetBooksCount_ReturnsZeroWhenOrganizationsLengthIsNull()
    {
        // Arrange
        Organization[] organizations = new Organization[0];

        // Act
        int result = Program.GetBooksCount(organizations);

        // Assert
        Assert.Equal(0, result);
    }

    [Fact]
    public void Program_GetBooksCount_OrganizationsWithoutLibrariesReturnsZero()
    {
        // Arrange
        Organization[] organizations = new Organization[1] { new Organization() };

        // Act
        int result = Program.GetBooksCount(organizations);

        // Assert
        Assert.Equal(0, result);
    }

    [Fact]
    public void Program_GetBooksCount_OrganizationsWithOneLibraryReturnsZero()
    {
        // Arrange
        Organization[] organizations = new Organization[] {
            new Organization(),
            new Library("LibraryName", "LibraryAddress", 100, 100)
        };

        // Act
        int result = Program.GetBooksCount(organizations);

        // Assert
        Assert.Equal(100, result);
    }

    [Fact]
    public void Program_GetBooksCount_OrganizationsWithSeveralLibrariesReturnsZero()
    {
        // Arrange
        Organization[] organizations = new Organization[3] {
            new Organization(),
            new Library("LibraryName1", "LibraryAddress1", 100, 100),
            new Library("LibraryName2", "LibraryAddress2", 100, 200)
        };

        // Act
        int result = Program.GetBooksCount(organizations);

        // Assert
        Assert.Equal(300, result);
    }

    [Fact]
    public void Program_BinarySearchByEmployeesCount_ReturnsNullWhenOrganizationsIsNull()
    {
        // Arrange

        // Act
        Organization? result = Program.BinarySearchByEmployeesCount(null, 0);

        // Assert
        Assert.Null(result);
    }

    [Fact]
    public void Program_BinarySearchByEmployeesCount_ReturnsNullWhenInvalidTarget()
    {
        // Arrange
        Organization[] organizations = new Organization[] {
            new Organization("OrgName1", "OrgAddress1", 100),
            new Organization("OrgName2", "OrgAddress2", 200),
            new Organization("OrgName3", "OrgAddress3", 300)
        };

        // Act
        Organization? result = Program.BinarySearchByEmployeesCount(organizations, 0);

        // Assert
        Assert.Null(result);
    }

    [Fact]
    public void Program_BinarySearchByEmployeesCount_ReturnsValidFirstObject()
    {
        // Arrange
        Organization[] organizations = new Organization[] {
            new Organization("OrgName1", "OrgAddress1", 100),
            new Organization("OrgName2", "OrgAddress2", 200),
            new Organization("OrgName3", "OrgAddress3", 300)
        };

        // Act
        Organization? result = Program.BinarySearchByEmployeesCount(organizations, 100);

        // Assert
        Assert.Equal(organizations[0], result);
    }

    [Fact]
    public void Program_BinarySearchByEmployeesCount_ReturnsValidLastObject()
    {
        // Arrange
        Organization[] organizations = new Organization[] {
            new Organization("OrgName1", "OrgAddress1", 100),
            new Organization("OrgName2", "OrgAddress2", 200),
            new Organization("OrgName3", "OrgAddress3", 300)
        };

        // Act
        Organization? result = Program.BinarySearchByEmployeesCount(organizations, 300);

        // Assert
        Assert.Equal(organizations[2], result);
    }
}
