/*
============
Pseudocode
============

convertToInt(schedule1[]);
convertToInt(schedule2[]);
convertToInt(dailyAct1[]);
convertToInt(dailyAct2[]);
overallDailyAct.start = max(dailyAct1[] start, dailyAct2[] start);
overallDailyAct.end = min(dailyAct1[] end, dailyAct2[] end);
availability1 = findAvailability(schedule1[], overallDailyAct);
availability2 = findAvailability(schedule2[], overallDailyAct);


while(schedules have not been fully parsed) {

	while(availablity1.interval[i] is not in same range as availability2.interval[i]) {
		move the earliest interval to the next one.
	})

	minPtr = min(availability1.interval[i], availability2.interval[i]);
	maxPtr = max(availability1.interval[i], availability2.interval[i]);

	if(minPtr < maxPtr) {
		availableTimes.push_back([minPtr, maxPtr]);
	}
}

convertToTime(availableTimes);
print(availableTimes);
*/
