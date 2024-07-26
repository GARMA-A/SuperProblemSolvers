# **🛠️ Contribution Rules 🛠️**

## **🔱 Create a Fork or Branch 🔱** 
### **🔴Name it with the feature name you want to add followed by your name.**
### **🔴Example: addBigIntFunctions-Girgis**

## **📁File Structure📂**
### **🔴Each topic is in its own folder.**
### **🔴Each file contains at most 10 functions, solving up to 10 different problems.**

## **👀Functions👀**
### **🔴Function names describe their purpose.**
### **🔴At the beginning of each function, include comments explaining:**
#### **1) The problem the function addresses.**
#### **2) The solution approach.**
#### **2) The time complexity.**
#### **4) If the problem was solved on LeetCode, Codeforces, or another problem-solving platform,**
#### **provide the link in the comments.**


# **📚The Repo Content Summary📚**

## **➕➖ BigInt first 10**

### **1️⃣ sumBigInts(vector<int>n1,vector<int>n2):vector<int>**
#### **🔍 Sum two digit vectors and return the resulting vector**
#### **🔍 There is also a string version: sumBigInts(string s1, string s2): string**

### **2️⃣ bigFactorial(int n):vector<int>**
#### **🔍 Calculate the factorial of a number up to a 1000-digit number**

## **🔢 BitWise first 10**

### **1️⃣ isOdd(Long Long): bool**
#### **🔍 Check if the given number is odd or not**

### **2️⃣ isPowerOfTwo(Long Long n): bool**
#### **🔍 If the number is a power of 2, return true; otherwise, return false**

### **3️⃣ countBits(Long Long n): int**
#### **🔍 Given any number, output the number of ones in its binary representation**

### **4️⃣ getIthBit(Long Long n, int index): bool**
#### **🔍 Return the ith bit for a given number**

### **5️⃣ setIthBit(Long Long &n, int index, bool seterValue=0): void**
#### **🔍 Set the ith bit to 0 or 1, changing the original number**

### **6️⃣ clearFirstNthBits(Long Long &n, int endPos): void**
#### **🔍 Set the first n bits to zeros (inclusive)**

### **7️⃣ clearRangeOfBits(Long Long &n, int startPos, int endPos): void**
#### **🔍 From startPos to endPos, set all bits to zeros (inclusive)**

### **8️⃣ setRangeOfBits(Long Long &n, int startPos, int endPos, bool seterValue): void**
#### **🔍 From startPos to endPos, set all bits to one or zero (inclusive)**

### **9️⃣ convertToDecimal(string bin): Long Long**

### **🔟 convertToBinary(Long Long n): Long Long**
#### **🔍 There is also convertToBinary(Long Long n): string a string version**

## **🔢 BitWise second 10**

### **1️⃣ unique2NPlus1Seq(vector<int> seq):int**
##### **🔍 Given 2n+1 numbers all apear twice except one number return that unique number**
##### **🔍 Thers is second version return pair of unique numbers in 2N+2 seq**

### **2️⃣ unique3NPlus1Seq(vector<int>seq):int**
##### **🔍 Almost all numbers apear 3 times except one number i want that number**

### **3️⃣ generateAllSubsequences(string str):vector<string>**
##### **🔍 Given str="abc" return vector={"","a","b","c","ab","ac","bc","abc"}**

### **4️⃣ travellingSalesMan(vector<vector<int>>&dist,int setOfBits,int startingNode):int**
##### **🔍 Recursive function to get shortest path of a graph (A->B->C->D->A)**
