# link: https://www.hackerrank.com/challenges/find-a-string/problem

def count_substring(string, sub_string):
    counter=0
    if len(sub_string)>len(string):     #if the length of substring is bigger than the string's length, then there is no need to continue
        return 0
    else:       #checking the string if contains the substring, starting in any possible position
        for i in range(0,len(string)-len(sub_string)+1):    #substring can start from position 0, to position len(string)-len(substring)
            if string[i:i+len(sub_string)]==sub_string:     #checking if we found the substring
                counter=counter+1   
    return counter


if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)