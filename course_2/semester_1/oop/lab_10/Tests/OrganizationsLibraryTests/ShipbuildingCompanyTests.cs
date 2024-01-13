using OrganizationsLibrary;

namespace OrganizationsLibraryTests;

public class ShipbuildingCompanyTests
{
    [Fact]
    public void ShipbuildingCompany_ShipsCountSetter_RetunsZero()
    {
        // Arrange
        var shipComp = new ShipbuildingCompany();
        shipComp.ShipsCount = -1;

        // Act
        int result = shipComp.ShipsCount;

        // Assert
        Assert.Equal(0, result);
    }

    [Fact]
    public void ShipbuildingCompany_ShallowCopy_ReturnsEqualButNotSameInstance()
    {
        // Arrange
        var shipComp1 = new ShipbuildingCompany();
        shipComp1.manager = new Manager("ManagerName");

        // Act
        var shipComp2 = shipComp1.ShallowCopy();

        // Assert
        Assert.Equal(shipComp1, shipComp2);
        Assert.Equal(shipComp1.ShipsCount, shipComp2.ShipsCount);
        Assert.NotSame(shipComp1, shipComp2);
        Assert.Same(shipComp1.manager, shipComp2.manager);
    }

    [Fact]
    public void ShipbuildingCompany_Clone_ReturnsEqualButNotSameInstanceWithClonedManager()
    {
        // Arrange
        var shipComp1 = new ShipbuildingCompany("ShipbuildingCompName", "ShipbuildingCompAddress", 100, 100);
        shipComp1.manager = new Manager("ManagerName");

        // Act
        var shipComp2 = (ShipbuildingCompany)shipComp1.Clone();

        // Assert
        Assert.Equal(shipComp1, shipComp2);
        Assert.NotSame(shipComp1, shipComp2);
        Assert.Equal(shipComp1.ShipsCount, shipComp2.ShipsCount);
        Assert.Equal(shipComp1.manager.Name, shipComp2.manager.Name);
        Assert.NotSame(shipComp1.manager, shipComp2.manager);
    }
}
