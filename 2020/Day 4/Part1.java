package day4;

import java.util.Scanner;
import java.io.File;
import java.util.HashMap;

public class Day4 {

    public static boolean isValidPassport(HashMap<String, String> passport){
        if (passport.get("ecl") == null){
            return false;
        }else if (passport.get("eyr") == null){
            return false;
        }else if (passport.get("hcl") == null){
            return false;
        }else if (passport.get("byr") == null){
            return false;
        }else if (passport.get("iyr") == null){
            return false;
        }else if (passport.get("hgt") == null){
            return false;
        }else if (passport.get("pid") == null){
            return false;
        }
        return true;
    }

    public static void main (String[] argv){
        File file = new File("./input.txt");
        Scanner s = null;
        try {
            s = new Scanner(file).useDelimiter("\n\n");
        } catch (Exception e) {
            System.out.println(e);
        }
        int validPassportCount = 0;
        while (s.hasNext()){
            HashMap<String, String> passport = new HashMap<String, String>();
            String entry = s.next();
            String[] tokenisedEntry = entry.strip().split("[ \n]");
            for (int i=0; i<tokenisedEntry.length; ++i){
               String[] keyValue = tokenisedEntry[i].split(":");
               passport.put(keyValue[0], keyValue[1]);
            }
            System.out.println(passport);
            System.out.println(isValidPassport(passport));
            if (isValidPassport(passport)) validPassportCount++;
        }
        System.out.println(validPassportCount);
    }
}