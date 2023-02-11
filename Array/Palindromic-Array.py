# Your task is to complete this function
# Function should return True/False or 1/0

def isPalindrome(s):    #ANS**
    s=str(s)
    return s == s[::-1]

def PalinArray(arr ,n):   #ANS**
    
    flag=0
    
    for i in arr:
        if(isPalindrome(i)):
            flag=1
        else:
            return 0
            

    return 1


#{ 
 # Driver Code Starts
# Driver Program
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        if PalinArray(arr, n):
            print(1)
        else:
            print(0)
# Contributed By: Harshit Sidhwa

# } Driver Code Ends