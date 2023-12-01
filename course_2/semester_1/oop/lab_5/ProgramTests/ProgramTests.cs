using lab_5;

namespace ProgramTests
{
    public class ProgramTests
    {
        [Fact]
        public void Program_DeleteWithPos_ReturnsArr()
        {
            // Arrange
            int[] input1 = { 1, 2, 3, 4, 5 };
            int[] input2 = { 1 };

            int pos1 = 4;
            int pos2 = 1;

            int[] expected1 = { 1, 2, 3, 5 };
            int[] expected2 = { };

            // Act
            int[] result1 = Program.DeleteWithPos(input1, pos1);
            int[] result2 = Program.DeleteWithPos(input2, pos2);

            // Assert
            Assert.Equal(expected1, result1);
            Assert.Equal(expected2, result2);
        }
        [Fact]
        public void Program_DeleteWithPos_ReturnsEmptyArr()
        {
            // Arrange
            int[] input = { };
            int pos = 1;
            int[] expected = { };

            // Act
            int[] result = Program.DeleteWithPos(input, pos);

            // Assert
            Assert.Equal(expected, result);
        }
        [Fact]
        public void Program_DeleteWithPos_ReturnsInvalidPos()
        {
            // Arrange
            int[] input = { 1, 2, 3 };
            int pos = 0;
            int[] expected = { 1, 2, 3 };

            // Act
            int[] result = Program.DeleteWithPos(input, pos);

            // Assert
            Assert.Equal(expected, result);
        }

        [Fact]
        public void Program_InsertRows_ReturnsEmptyArr()
        {
            // Arrange
            int[,] input = { };
            int[,] expected = { };

            // Act
            int[,] result = Program.InsertRows(input);

            // Assert
            Assert.Equal(expected, result);
        }

        [Fact]
        public void Program_InsertRows_ReturnsArr()
        {
            // Arrange
            int[,] input1 = { { 1, 2 }, { 3, 4 } };
            int[,] input2 = { { 1 } };

            int[,] expected1 = { { 1, 2 }, { 3, 4 }, { 1, 1 } };
            int[,] expected2 = { { 1 } };

            // Act
            int[,] result1 = Program.InsertRows(input1);
            int[,] result2 = Program.InsertRows(input2);

            // Assert
            Assert.Equal(expected1, result1);
            Assert.Equal(expected2, result2);
        }

        [Fact]
        public void Program_AddRowAtEnd_ReturnsEmptyArr()
        {
            // Arrange
            int[][] input = { };

            // Act
            int[][] result = Program.AddRowAtEnd(input, 1);

            // Assert
            Assert.Equal(input, result);
        }

        [Fact]
        public void Program_AddRowAtEnd_ReturnsArrWithOneNumber()
        {
            // Arrange
            int[][] input = new int[1][];
            input[0] = new int[1] { 1 };

            // Act
            int[][] result = Program.AddRowAtEnd(input, 1);

            // Assert
            Assert.True(result.Length == 2);
        }
        [Fact]
        public void Program_AddRowAtEnd_ReturnsArr()
        {
            // Arrange
            int[][] input1 = new int[2][];
            input1[0] = new int[] { 1, 2, 3 };
            input1[1] = new int[] { 3, 2, 1 };

            // Act
            int[][] result = Program.AddRowAtEnd(input1, 1);

            // Assert
            Assert.True(result.Length == 3);
        }

        [Fact]
        public void Program_PrintArray_PrintErrorOneDimArr()
        {
            // Assert
            int[] input = new int[] { };
            string expected = "Размер массива равен 0!\r\n";

            var stringWriter = new StringWriter();
            Console.SetOut(stringWriter);

            // Act
            Program.PrintArray(input);
            var output = stringWriter.ToString();

            // Assert
            Assert.Equal(expected, output);
        }

        [Theory]
        [InlineData(new int[] { 1, 2, 3 })]
        [InlineData(new int[] { 1 })]
        public void Program_PrintArray_PrintOneDimArr(int[] arr)
        {
            // Arrange
            string expected = "";

            var stringWriter = new StringWriter();
            Console.SetOut(stringWriter);

            // Act
            foreach (int item in arr)
            {
                expected += item + " ";
            }
            expected += "\r\n";

            Program.PrintArray(arr);

            var output = stringWriter.ToString();

            // Assert
            Assert.Equal(expected, output);
        }

        [Fact]
        public void Program_PrintArray_PrintErrorTwoDimArr()
        {
            // Arrange
            int[,] input = { };
            string expected = "Размер массива равен 0!\r\n";

            var stringWriter = new StringWriter();
            Console.SetOut(stringWriter);

            // Act
            Program.PrintArray(input);

            var output = stringWriter.ToString();

            // Assert
            Assert.Equal(expected, output);
        }

        [Fact]
        public void Program_PrintArray_PrintTwoDimArr()
        {
            // Arrange
            int[,] input1 = { { 1 } };
            int[,] input2 = { { 1, 2, 3 }, { 4, 5, 6 } };

            var stringWriter = new StringWriter();
            Console.SetOut(stringWriter);

            string expected = "";

            // Act
            foreach (int item in input1)
            {
                expected += item + " ";
            }
            expected += "\r\n";
            for (int i = 0; i < input2.GetLength(0); i++)
            {
                for (int j = 0; j < input2.GetLength(1); j++)
                {
                    expected += input2[i, j] + " ";
                }
                expected += "\r\n";
            }

            Program.PrintArray(input1);
            Program.PrintArray(input2);

            var output = stringWriter.ToString();

            // Assert
            Assert.Equal(expected, output);
        }

        [Fact]
        public void Program_PrintArray_PrintErrorJaggedArr()
        {
            // Arrange
            int[][] input = { };
            string expected = "Размер массива равен 0!\r\n";

            var stringWriter = new StringWriter();
            Console.SetOut(stringWriter);

            // Act
            Program.PrintArray(input);

            var output = stringWriter.ToString();

            // Assert
            Assert.Equal(expected, output);
        }

        [Fact]
        public void Program_PrintArray_PrintJaggedArr()
        {
            // Arrange
            int[][] input1 = new int[1][];
            input1[0] = new int[] { 1 };
            int[][] input2 = new int[2][];
            input2[0] = new int[] { 1, 2 };
            input2[1] = new int[] { 3, 4, 5 };

            string expected = "";

            var stringWriter = new StringWriter();
            Console.SetOut(stringWriter);

            // Act
            for (int i = 0; i < input1.GetLength(0); i++)
            {
                for (int j = 0; j < input1[i].Length; j++)
                {
                    expected += input1[i][j] + " ";
                }
                expected += "\r\n";
            }
            for (int i = 0; i < input2.GetLength(0); i++)
            {
                for (int j = 0; j < input2[i].Length; j++)
                {
                    expected += input2[i][j] + " ";
                }
                expected += "\r\n";
            }
            Program.PrintArray(input1);
            Program.PrintArray(input2);

            var output = stringWriter.ToString();

            // Assert
            Assert.Equal(expected, output);
        }
    }
}