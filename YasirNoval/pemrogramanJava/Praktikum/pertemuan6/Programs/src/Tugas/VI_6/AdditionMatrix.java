package Tugas.VI_6;

import java.util.Scanner;

public class AdditionMatrix {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int row, col;

        System.out.print("Input Row: ");
        row = input.nextInt();

        System.out.print("Input Col: ");
        col = input.nextInt();

        int[][] aMatrix = new int[row][];
        int[][] bMatrix = new int[row][];
        int[][] cMatrix = new int[row][];

        if (row == col) {
            // addition matrix A + Matrix B = Matrix C
            for (int i = 0; i < cMatrix.length; i++) {
                aMatrix[i] = new int[col];
                bMatrix[i] = new int[col];
                cMatrix[i] = new int[col];

                for (int j = 0; j < cMatrix[i].length; j++) {
                    aMatrix[i][j] = i + j;
                    bMatrix[i][j] = i + j;
                    cMatrix[i][j] = aMatrix[i][j] + bMatrix[i][j];
                }
            }

            // print matrix
            for (int[] matrix : cMatrix) {
                for (int i : matrix) {
                    System.out.print(i + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println("E: cannot do the matrix addition because the row and column values are not the same");
        }
    }
}
