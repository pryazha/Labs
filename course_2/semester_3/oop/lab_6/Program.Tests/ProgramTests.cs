using lab_6;

namespace ProgramTests
{
    public class ProgramTest
    {
        [Fact]
        public void Program_DeleteColumn_ReturnsErr()
        {
            // Arrange
            int[,] input1 = {};
            int[,] input2 = { { 1, 2, 3 }, { 3, 5, 6 } };

            // Act
            int[,] result1 = Program.DeleteColumn(input1, 0);
            int[,] result2 = Program.DeleteColumn(input2, 3);

            // Assert
            Assert.Equal(input1, result1);
            Assert.Equal(input2, result2);
        }

        [Fact]
        public void Program_DeleteColumn_ReturnsArr() {
            // Arrange
            int[,] input1 = { { 1, 2 }, { 3, 4 } };
            int[,] input2 = { { 1 } };

            int[,] expected1 = { { 1 }, { 3 } };
            int[,] expected2 = { {} };

            // Act
            int[,] result1 = Program.DeleteColumn(input1, 1);
            int[,] result2 = Program.DeleteColumn(input2, 0);

            // Assert
            Assert.Equal(expected1, result1);
            Assert.Equal(expected2, result2);
        }

        [Fact]
        public void Program_FindShortestId_ReturnsEmptyString()
        {
            // Arrange
            string input = "";

            // Act
            string result = Program.FindShortestId(input);

            // Assert
            Assert.Equal(input, result);
        }

        [Theory]
        [InlineData("abc", "abc")]
        [InlineData("This is text.", "is")]
        [InlineData("Some text. _s", "_s")]
        [InlineData("Variable1, _var, size, _Column_Count_", "_var")]
        [InlineData(".9840 435 328u9", "")]
        public void Program_FindShortestId_ReturnsValidId(string input, string expected)
        {
            // Arrange

            // Act
            string result = Program.FindShortestId(input);

            // Assert
            Assert.Equal(expected, result);
        }

        [Fact]
        public void Program_FindLastMinColumn_ReturnsErr()
        {
            // Arrange
            int[,] input = {};
            int expected = -1;

            // Act
            int result = Program.FindLastMinColumn(input);

            // Assert
            Assert.Equal(expected, result);
        }

        [Fact]
        public void Program_FindLastMinColumn_ReturnsValidColumn()
        {
            // Arrange
            int[,] input1 = { { 1 } };
            int expected1 = 0;
            int[,] input2 = { { 1, 2, 3 }, { 3, 2, 1 } };
            int expected2 = 2;

            // Act
            int result1 = Program.FindLastMinColumn(input1);
            int result2 = Program.FindLastMinColumn(input2);

            // Assert
            Assert.Equal(expected1, result1);
            Assert.Equal(expected2, result2);
        }

        [Fact]
        public void Program_GenerateRandomString_ReturnsEmptyString()
        {
            // Arrange
            Random rnd = new Random();
            int size = 0;

            // Act
            string result = Program.GenerateRandomString(rnd, size);

            // Assert
            Assert.Equal("", result);
        }

        [Fact]
        public void Program_GenerateRandomString_ReturnsValidString()
        {
            // Arrange
            Random rnd = new Random();
            int size = 5;

            // Act
            string result = Program.GenerateRandomString(rnd, size);

            // Assert
            Assert.Equal(size, result.Length);
        }
    }
}
