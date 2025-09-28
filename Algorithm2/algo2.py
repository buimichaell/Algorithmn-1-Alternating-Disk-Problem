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
import datetime

# function used to read input and store all variables as global. additional global variable called num_people for loop use
def load_and_set_globals(filename):
    with open(filename, "r") as file:
        data = file.read()

    exec(data, globals())

    global all_schedules, all_availabilities, num_people
    all_schedules = []
    all_availabilities = []
    person_num = 1

    while True:
        schedule_var = f'person{person_num}_Schedule'
        avail_var = f'person{person_num}_DailyAct'

        if schedule_var in globals() and avail_var in globals():
            all_schedules.append(globals()[schedule_var])
            all_availabilities.append(globals()[avail_var])
            person_num += 1
        else:
            break
    num_people = len(all_schedules)

# read the input
load_and_set_globals("sample_input.txt")


"""Method converting time string for comparison"""
def conTime(time):
    time_format = "%H:%M"
    return datetime.datetime.strptime(time, time_format)


"""Function that returns a persons availability in time intervals given their schedule and availability"""
def AvailabilityIntervals(sched, avail):
    current = conTime(avail[0])
    last = conTime(avail[1])
    gap_times = [] # empty list to hold available time gaps

    # iterates through the schedule of busy times
    for start_str, end_str in sched:
        start = conTime(start_str)
        end = conTime(end_str)

        # append if the starting time of an interval is bigger
        if start > current:
            gap_times.append([current.strftime("%H:%M"), start.strftime("%H:%M")])
            current = end

        current = max(current, end) # current will equal the biggest time 
    # appends if current is less than last available time
    if current < last:
        gap_times.append([current.strftime("%H:%M"), last.strftime("%H:%M")])

    return gap_times


"""Function that will compare the combined schedule and available times"""
def FindTimes(sched, avail):
    sched_list, avail_list, both_free = []

    # converts list for comparison
    for start, end in sched_list:
        conTime(start)
        conTime(end)
        sched_list.append([start, end])
     # converts list for comparison
    for start, end in avail_list:
        conTime(start)
        conTime(end)
        avail_list.append([start, end])

    current = avail_list[0][0] # current set to first time in availability


# below runs AvailabilityIntervals() for all schedules and stores it into new_sched1, new_sched2, ...
for i in range(num_people):
    availability = AvailabilityIntervals(all_schedules[i], all_availabilities[i])
    globals()[f'new_sched{i+1}'] = availability

gap_sched = new_sched1 + new_sched2
print("Gap:", gap_sched)






