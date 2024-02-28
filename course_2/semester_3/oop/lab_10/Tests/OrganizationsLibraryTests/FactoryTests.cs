using OrganizationsLibrary;

namespace OrganizationsLibraryTests;

public class FactoryTests
{
    [Fact]
    public void Factory_Constructor_CreatedProductNegative_ReturnsZero()
    {
        // Arrange
        var factory = new Factory();
        factory.CreatedProducts = -1;

        // Act
        int result = factory.CreatedProducts;

        // Assert
        Assert.Equal(0, result);
    }

    [Fact]
    public void Factory_ShallowCopy_ReturnsEqualButNotSameInstance()
    {
        // Arrange
        var factory1 = new Factory("FactoryName", "FactoryAddress", 100, 10);
        factory1.manager = new Manager("ManagerName");

        // Act
        var factory2 = factory1.ShallowCopy();

        // Assert
        Assert.Equal(factory1, factory2);
        Assert.Equal(factory1.CreatedProducts, factory2.CreatedProducts);
        Assert.NotSame(factory1, factory2);
        Assert.Same(factory1.manager, factory2.manager);
    }

    [Fact]
    public void Organization_Clone_ReturnsEqualButNotSameInstanceWithClonedManager()
    {
        // Arrange
        var factory1 = new Factory("FactoryName", "FactoryAddress", 100, 10);
        factory1.manager = new Manager("ManagerName");

        // Act
        var factory2 = (Factory)factory1.Clone();

        // Assert
        Assert.Equal(factory1, factory2);
        Assert.NotSame(factory1, factory2);
        Assert.Equal(factory1.CreatedProducts, factory2.CreatedProducts);
        Assert.Equal(factory1.manager.Name, factory2.manager.Name);
        Assert.NotSame(factory1.manager, factory2.manager);
    }
}
