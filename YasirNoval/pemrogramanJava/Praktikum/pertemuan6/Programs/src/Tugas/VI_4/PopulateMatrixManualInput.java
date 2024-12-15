package Tugas.VI_4;

import java.util.Scanner;

public class PopulateMatrixManualInput {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int row, col;

        System.out.print("Input Row: ");
        row = input.nextInt();

        System.out.print("Input col: ");
        col = input.nextInt();

        int[][] aMatrix = new int[row][];

        // populate matrix
        for (int i = 0; i < aMatrix.length; i++) {
            aMatrix[i] = new int[col];    // create sub-array
            for (int j = 0; j < aMatrix[i].length; j++) {
                aMatrix[i][j] = i + j;
            }
        }

        // print matrix
        for (int[] matrix : aMatrix) {
            for (int i : matrix) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
