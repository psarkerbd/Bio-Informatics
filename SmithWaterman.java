/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package smithwaterman;
import java.util.*;

/**
 *
 * @author FC
 */

class localAlignment{
    int [][] alignment;
    char [] ls, rs;
    
    void initialization(int row, int col)
    {
        alignment = new int [row][col];
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                alignment[i][j] = 0;
            }
        }
    }
    
    void calculateAlignmentScore(int row, int col, int match, int mismatch, int gap)
    {
        int horizontal=0, vertical=0, diagonal=0;
        
        for(int i=1; i<row; i++)
        {
            for(int j=1; j<col; j++)
            {
                //System.out.print(alignment[i][j] + " ");
                horizontal = alignment[i][j-1] + gap;
                if(horizontal < 0) horizontal = 0;
                vertical = alignment[i-1][j] + gap;
                if(vertical < 0) vertical = 0;
                //check diagonal
                alignment[i][j] = alignment[i-1][j-1];
                if(ls[i-1] == rs[j-1])
                {
                    //System.out.print(ls[i-1] + " " + rs[j-1]);
                    diagonal = alignment[i][j] + match;
                }
                
                else
                {
                    diagonal = alignment[i][j] + mismatch;
                }
                
                if(diagonal < 0) diagonal = 0;
                
                alignment[i][j] = Math.max(horizontal, vertical);
                alignment[i][j] = Math.max(alignment[i][j], diagonal);
                
                //System.out.println("");
            }
            
            //System.out.println("");
        }
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                System.out.print(alignment[i][j] + " ");
            }
            
            System.out.println("");
        }
    }
}


public class SmithWaterman {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        localAlignment la = new localAlignment();
        Scanner sc = new Scanner(System.in);
        String LS = "AGCT";
        String RS = "ATGCT";
        int m = LS.length()+1, n = RS.length()+1;
        //int [][] alignment = new int [m][n];
        int match = 1, mismatch = -1, gap = -2;
        //initialization
        la.ls = LS.toCharArray();
        la.rs = RS.toCharArray();
        la.initialization(m, n);
        la.calculateAlignmentScore(m, n, match, mismatch, gap);
    }
    
}
