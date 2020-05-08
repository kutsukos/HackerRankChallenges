# https://www.hackerrank.com/challenges/find-a-string/problem

def count_substring(string, sub_string):
    points=0
    if len(sub_string)>len(string):
        return 0
    else:
        for i in range(0,len(string)-len(sub_string)+1):
            m_flag=1
            for y in range(0,len(sub_string)):
                if(string[i+y]!=sub_string[y]):
                    m_flag=0
            if(m_flag==1):
                points=points+1
    return points

    



if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)