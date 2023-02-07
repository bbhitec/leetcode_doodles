##!/usr/bin/env python
'''
    @author [mst]
    @brief  hackerrank problems series

    hr_time_conversion
    https://www.hackerrank.com/challenges/time-conversion/problem

    Given a time in -hour AM/PM format, convert it to military (24-hour) time.
    Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
    - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

    gains:
    -python string manipulation
    -working with re (regex)

    @version 0.1 2023.02
'''

import re


# solution using
# [demo] regex and grouping
def timeConversion(s):

    # this re groups matches according to format given
    # [demo] r"" string will not consider escape characters
    # [demo] the expressiong "(?P<name>..)" will capture a group accessible by "<name>" of two characters
    times = re.search(r"(?P<hh>..):(?P<mm>..):(?P<ss>..)(?P<ampm>..)", s)
    hour = times.group('hh')
    if times.group('ampm') == 'PM':
        if hour == '12':
            hr = '12'
        else:
            hr = str(int(hour) + 12)
    else:
        if hour == '12':
            hr = '00'
        else:
            hr = hour
    res = hr + ':' + times.group('mm') + ':' + times.group('ss')
    # print (res)
    return res

# solution using the
# [demo] useful python string/list indexing
def timeConversion2(s):
    if s[-2:] == "AM" and s[:2] == "12":
        return "00" + s[2:-2]
    elif s[-2:] == "AM":
        return s[:-2]
    elif s[-2:] == "PM" and s[:2] == "12":
        return s[:-2]
    else:
       ans = int(s[:2]) + 12
       return str(str(ans) + s[2:8])

################## DRIVER
def main():

    # supplied input reader
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')
    # s = input()
    # result = timeConversion(s)
    # fptr.write(result + '\n')
    # fptr.close()

    s = "07:05:45PM" # input()
    result = timeConversion(s)
    print (result)



if __name__ == ("__main__"):
    main()
