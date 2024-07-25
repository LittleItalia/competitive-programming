import re
from email.utils import parseaddr, formataddr

def is_valid_email(email):
    pattern = r'^[a-z][\w\-\.]+@[a-z]+\.[a-z]{1,3}$'
    parsed_addr = parseaddr(email)

    if(re.search(pattern, parsed_addr[1])):
        return True
    return False


n = int(input())
for _ in range(n):
    information = input()
    if(is_valid_email(information)):
        name, email = information.split()
        name, email = str(name), str(email)

        print(name, email)