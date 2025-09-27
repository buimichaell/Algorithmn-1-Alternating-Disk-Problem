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



