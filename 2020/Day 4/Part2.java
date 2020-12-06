package day4;

import java.util.Scanner;
import java.io.File;
import java.util.HashMap;
import java.util.Arrays;
import java.util.List;

public class Day4 {
    public static boolean isValidBirthYear(String birthYearString){
        if (birthYearString.length() != 4) return false;
        int birthYear = 0;
        try {
            birthYear = Integer.parseInt(birthYearString);
        }catch(Exception e){
            return false;
        }
        return birthYear >= 1920 && birthYear <= 2020;
    }

    public static boolean isValidIssueYear(String issueYearString){
        if (issueYearString.length() != 4) return false;
        int issueYear = 0;
        try {
            issueYear = Integer.parseInt(issueYearString);
        }catch(Exception e){
            return false;
        }
        return issueYear >= 2010 && issueYear <= 2020;
    }

    public static boolean isValidExpirationYear(String expirationYearString){
        if (expirationYearString.length() != 4) return false;
        int expirationYear = 0;
        try {
            expirationYear = Integer.parseInt(expirationYearString);
        }catch(Exception e){
            return false;
        }
        return expirationYear >= 2020 && expirationYear <= 2030;
    }

    public static boolean isValidHeight(String heightString){
        String[] lengtAndUnits = heightString.split("(?<=\\D)(?=\\d)|(?<=\\d)(?=\\D)");
        if (lengtAndUnits.length != 2) return false;
        int length = 0;
        try {
            length = Integer.parseInt(lengtAndUnits[0]);
        }catch(Exception e){
            return false;
        }
        String units = lengtAndUnits[1];
        switch (units) {
            case "cm":
                if (length < 150 || length > 193)
                    return false;
                break;
        
            case "in":
                if (length < 59 || length > 76)
                    return false;
                break;
            default:
                return false;
        }
        return true;
    }

    public static boolean isValidHairColor(String hairColor){
        return hairColor.matches("#[0-9a-f]{6}");
    }

    public static boolean isValidEyeColor(String eyeColor){
        List<String> colors =  Arrays.asList("amb","blu","brn","gry","grn","hzl","oth");
        return colors.contains(eyeColor);
    }

    public static boolean isValidPassportId(String passportId){
        return passportId.matches("[0-9]{9}");
    }

    public static boolean hasAllRequiredFields (HashMap<String, String> passport){
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
    public static boolean isValidPassport(HashMap<String, String> passport){
        if (!hasAllRequiredFields(passport)) return false;

        if (!isValidEyeColor(passport.get("ecl")))
            return false;
        if (!isValidExpirationYear(passport.get("eyr")))
            return false;
        if (!isValidHairColor(passport.get("hcl")))
            return false;
        if (!isValidBirthYear(passport.get("byr")))
            return false;
        if (!isValidIssueYear(passport.get("iyr")))
            return false;
        if (!isValidHeight(passport.get("hgt")))
            return false;
        if (!isValidPassportId(passport.get("pid")))
            return false;
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
            if (isValidPassport(passport)) validPassportCount++;
        }
        System.out.println(validPassportCount);
    }
}