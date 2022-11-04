/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.lang.*;
import java.util.*;
public class InferringmRNAfromProtein {
    HashMap<Character, Integer> map = new HashMap<>();
    public String readingFile() throws Exception
    {
        File f = new File("rosalind_mrna.txt");
        BufferedReader br = new BufferedReader(new FileReader(f));
        String str, seq="";
        while((str = br.readLine()) != null)
        {
            //System.out.println(str + " ");
            seq += str;
            //bw.write(str + " ");
        }
    
        return seq;
    }
    public void codonMap()
    {
        map.put('F', 2); map.put('P', 4); map.put('K', 2);
        map.put('L', 6); map.put('H', 2); map.put('V', 4);
        map.put('S', 6); map.put('Q', 2); map.put('A', 4);
        map.put('Y', 2); map.put('R', 6); map.put('D', 2);
        map.put('C', 2); map.put('I', 3); map.put('E', 2);
        map.put('W', 1); map.put('M', 1); map.put('G', 4);
        map.put('T', 4); map.put('N', 2);
    }
    public int getFreq(char ch)
    {
        int val = 0;
        for(Map.Entry m : map.entrySet())
        {
            if(m.getKey().equals(ch))
            {
                val = (int)m.getValue();
            }
        }
        
        return val;
    }
    public static void main(String [] args) throws Exception
    {
        InferringmRNAfromProtein ob = new InferringmRNAfromProtein();
        String str = ob.readingFile();
        System.out.println(str);
        ob.codonMap();
        long x = 3;
        for(int i=0; i<str.length(); i++)
        {
            int y = ob.getFreq(str.charAt(i));
            x = ((x%1000000) * (y%1000000))%1000000;
            //System.out.println(x);
        }
        
        System.out.println(x);
    }
}
