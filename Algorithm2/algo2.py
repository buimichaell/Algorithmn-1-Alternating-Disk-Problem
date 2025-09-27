"""Pseudocode given sample input

 p1_sched = [sched1]
 p1_avail = [avail1]
 p2_sched = [sched2]
 p2_avail = [avail2]
 meeting_duration = 30

 combined_sched = [[p1_sched], [p2_sched]] 

# function that return a persons availability given their schedule
def AvailabilityInterval(schedule, availability)
    for start, end in schedule # iterates through schedule
        if are gaps: 
            gap_times.append(t1, t2) #appends interval times to a list
    return gap_times

# call function to find person 1's free time
person1 = AvailabilityInterval(p1_sched, p1_avail)

# call function to find person 2's free time
person2 = AvailabilityInterval(p2_sched, p2_avail)

meeting_times = [] # empty list returning a list of avaiable meeting times

# function taking in combined schedule and the people's availability interval list
def FindTimes(schedule, person1, person2)
    
    # iterate through the combined list of schedules
    for sched in combined_sched:
        if sched does not equal person1 and person 2 
            meeting_times.append(t1, t2) # time interval of meeting_duration length

    return meeting_times # list of times available for both to meet

"""

from datetime import datetime

# opens file to get sample input
with open("sample_input.txt", "r") as file:
    data = file.read()  # reads data
exec(data) # executes & defines variables

p1_sched = person1_Schedule  # list of times not available 
p1_avail = person1_DailyAct  # list of times available
p2_sched = person2_Schedule  # list of times not available 
p2_avail = person2_DailyAct  # list of times available
duration = duration_of_meeting


"""Method converting time string for comparison"""
def conTime(time):
    time_format = "%H:%M"
    conv_time = datetime.strptime(time, time_format)


"""Function that returns a persons availability in time intervals given their schedule and availability"""
def AvailabilityIntervals(sched, avail):
    avail_int = avail
    current = avail[0]
    last = avail[1]
    last_time = sched[-1][-1]
    schedule = []
    gap_times = []

    conTime(current)
    conTime(last)
    
    for start, end in sched:
        # print statements to check for errors
        print("Current:", current)
        print("Start:", start + ", " + end)
        print("Schedule:", sched)
        conTime(start)
        conTime(end)

        if start > current:
            gap_times.append([current, start])
        elif current > start and current > end:
            end_time = sched[1][0]
            gap_times.append([current, end_time])
            # current = end_time
        else:
            current = end 
        print("Gaps:", gap_times)

        if end < current:
            current = avail[0]
        current = end
        print("Current 2:", current,"\n") 


new_sched = AvailabilityIntervals(p1_sched, p1_avail)
print(new_sched,"\n")
new_sched2 = AvailabilityIntervals(p2_sched, p2_avail)
print(new_sched2)


