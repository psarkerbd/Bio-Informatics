
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author FC
 */
public class RNASplicing {
    String dna = "";
    ArrayList<String> dnaSub = new ArrayList<>();
    void readingFile() throws Exception
    {
        //File f = new File("rosalind_splc.txt");
        //BufferedReader br = new BufferedReader(new FileReader(f));
        File f = new File("rosalind_splc.txt");
        Scanner sc = new Scanner(new File("rosalind_splc.txt"));
        BufferedReader br = new BufferedReader(new FileReader(f));
        String str="", seq="";
        boolean isDNA = false;
        while(sc.hasNextLine())
        {
            str = "";
            if(sc.nextLine().contains(">"))
            {
                if(!isDNA)
                {
                    isDNA = true;
                    continue;
                }
                
                else
                {
                    //System.out.println(sc.next());
                    dnaSub.add(sc.next());
                }
            }
        }
        
        int cnt = 0;
        
        while((str = br.readLine()) != null)
        {
            //System.out.println(str + " ");
            seq += str;
            //bw.write(str + " ");
        }
        
        String copy="";
        
        for(int i=0; i<seq.length(); i++)
        {
            if(seq.charAt(i) == '>') cnt+=1;
            if(cnt == 2)
            {
                break;
            }
            else
            {
                copy += seq.charAt(i);
            }
        }
        
        System.out.println("> count = " + cnt);
        
        for(int i=0; i<copy.length(); i++)
        {
            if(copy.charAt(i)=='A' || copy.charAt(i)=='U' || copy.charAt(i)=='C' || copy.charAt(i)=='G' || copy.charAt(i)=='T')
            {
                dna += copy.charAt(i);
            }
        }
        
        System.out.println(dna);
        
        for(int i=0; i<dnaSub.size(); i++)
        {
            System.out.println(dnaSub.get(i));
        }
    }
    
    String transcribing(String seq)
    {
        char [] ch = new char [seq.length()];
        ch = seq.toCharArray();
        String rna = "";
        for(int i=0; i<seq.length(); i++)
        {
            if(ch[i] == 'T')
            {
                ch[i] = 'U';
            }
            
            rna += ch[i];
        }
        
        return rna;
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
        File f = new File("output.txt");
        BufferedWriter bw = new BufferedWriter(new FileWriter(f));
        RNASplicing ob = new RNASplicing();
        ob.readingFile();
        String substr = "";
        System.out.println("dna is : " + ob.dna);
        System.out.println("length of dna is " + ob.dna.length());
        for(int i=0; i<ob.dnaSub.size(); i++)
        {
            System.out.println(ob.dnaSub.get(i));
            substr = ob.dnaSub.get(i);
            if(ob.dna.contains(substr) && substr.length() < ob.dna.length())
            {
                System.out.println("contained");
                ob.dna = ob.dna.replace(substr, "");
            }
        }
        System.out.println("updated dna: " + ob.dna);
        System.out.println("updated length of dna is " + ob.dna.length());
        String getRNA = ob.transcribing(ob.dna), codon = "", protein = "";
        System.out.println("rna is " + getRNA + " length = " + getRNA.length());
        for(int i=0; i<getRNA.length(); i+=3)
        {
            int j = i;
            codon = "";
            while(j < i+3)
            {
                codon += getRNA.charAt(j);
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
