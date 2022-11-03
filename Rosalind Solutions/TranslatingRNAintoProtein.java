/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rosalindsolution;
import java.io.*;
/**
 *
 * @author FC
 */
public class TranslatingRNAintoProtein {
    String readingFile() throws Exception
    {
        File f = new File("rosalind_prot.txt");
        BufferedReader br = new BufferedReader(new FileReader(f));
        String str, seq="";
        while((str = br.readLine()) != null)
        {
            //System.out.println(str + " ");
            seq += str;
            //bw.write(str + " ");
        }
        
        String orin_seq = "";
        
        for(int i=0; i<seq.length(); i++)
        {
            if(seq.charAt(i)=='A' || seq.charAt(i)=='U' || seq.charAt(i)=='C' || seq.charAt(i)=='G' || seq.charAt(i)=='T')
            {
                orin_seq += seq.charAt(i);
            }
        }
        
        return orin_seq;
    }
    
    String transcription(String codon)
    {
        if(codon.equals("UUU") || codon.equals("UUC")) return "F";
        else if(codon.equals("UUA") || codon.equals("UUG")) return "L";
        else if(codon.equals("UCU") || codon.equals("UCC") || codon.equals("UCA") || codon.equals("UCG")) return "S";
        else if(codon.equals("UAU") || codon.equals("UAC")) return "Y";
        //else if(codon.equals("UAA") || codon.equals("UAG") || codon.equals("UGA")) return "Stop";
        else if(codon.equals("UGU") || codon.equals("UGC")) return "C";
        else if(codon.equals("UGG")) return "W";
        else if(codon.equals("CUU") || codon.equals("CUC") || codon.equals("CUA") || codon.equals("CUG")) return "L";
        else if(codon.equals("CCU") || codon.equals("CCC") || codon.equals("CCA") || codon.equals("CCG")) return "P";
        else if(codon.equals("CAU") || codon.equals("CAC")) return "H";
        else if(codon.equals("CAA") || codon.equals("CAG")) return "Q";
        else if(codon.equals("CGU") || codon.equals("CGC") || codon.equals("CGA") || codon.equals("CGG")) return "R";
        else if(codon.equals("AUU") || codon.equals("AUC") || codon.equals("AUA")) return "I";
        else if(codon.equals("AUG")) return "M";
        else if(codon.equals("ACU") || codon.equals("ACC") || codon.equals("ACA") || codon.equals("ACG")) return "T";
        else if(codon.equals("AAU") || codon.equals("AAC")) return "N";
        else if(codon.equals("AAA") || codon.equals("AAG")) return "K";
        else if(codon.equals("AGU") || codon.equals("AGC")) return "S";
        else if(codon.equals("AGA") || codon.equals("AGG")) return "R";
        else if(codon.equals("GUU") || codon.equals("GUC") || codon.equals("GUA") || codon.equals("GUG")) return "V";
        else if(codon.equals("GCU") || codon.equals("GCC") || codon.equals("GCA") || codon.equals("GCG")) return "A";
        else if(codon.equals("GAU") || codon.equals("GAC")) return "D";
        else if(codon.equals("GAA") || codon.equals("GAG")) return "E";
        else if(codon.equals("GGU") || codon.equals("GGC") || codon.equals("GGA") || codon.equals("GGG")) return "G";
        else return "";
    }
    public static void main(String [] args) throws Exception
    {
        TranslatingRNAintoProtein ob = new TranslatingRNAintoProtein();
        String str = ob.readingFile();
        System.out.println(str);
        File f = new File("output.txt");
        BufferedWriter bw = new BufferedWriter(new FileWriter(f));
        int len = str.length(), i, j;
        String protein = "", codon="";
        for(i=0; i<len; i+=3)
        {
            j = i;
            codon = "";
            while(j < i+3)
            {
                codon += str.charAt(j);
                j += 1;
            }
            //System.out.print(codon + " ");
            protein = ob.transcription(codon);
            System.out.print(protein);
            bw.write(protein);
        }
        System.out.println("");
        bw.close();
    }
}
