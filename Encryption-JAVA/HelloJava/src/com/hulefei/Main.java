package com.hulefei;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Main {

    public static void main(String[] args) throws NoSuchAlgorithmException {
        String original = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        md5test(original);
        System.out.println();
        shatest(original);
    }

    public static void shatest(String original) throws NoSuchAlgorithmException {
        String sha1 = encrypt(original, "sha-1");
        System.out.println("original:" + original);
        System.out.println("digested(hex):" + sha1);
    }

    public static void md5test(String original) throws NoSuchAlgorithmException {
        String md5 = encrypt(original, "MD5");
        System.out.println("original:" + original);
        System.out.println("digested(hex):" + md5);
    }

    public static String encrypt(String original,String algorithmName) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance(algorithmName);
        md.update(original.getBytes());
        byte[] digest = md.digest();
        return hex(digest);
    }

    private static String hex(byte[] digest) {
        StringBuilder sb = new StringBuilder();
        for (byte b : digest) {
            sb.append(String.format("%02x", b & 0xff));
        }
        return sb.toString();
    }
}
