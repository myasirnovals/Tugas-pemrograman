package Program.VI_5;

public class PopulateMatrix {
    public static void main(String[] args) {
        int[][] aMatrix = new int[4][];

        // populate matrix
        for (int i = 0; i < aMatrix.length; i++) {
            aMatrix[i] = new int[5];    // create sub-array
            for (int j = 0; j < aMatrix[i].length; j++) {
                aMatrix[i][j] = i + j;
            }
        }

        // print matrix
        for (int[] matrix : aMatrix) {
            for (int i : matrix) {
                System.out.print((i + i) + " ");
            }
            System.out.println();
        }
    }
}
