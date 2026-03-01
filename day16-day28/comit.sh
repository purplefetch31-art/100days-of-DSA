#!/bin/bash
Start_Date="2026-02-16"
for i in {0..12}
do
	DAY_NUM=$((16+i))
	FILENAME="day${DAY_NUM}.c"
	FILE_PATH="dsa-100daycode/day16-day28/$FILENAME"
	TARGET_DATE=$(date -d "$START_DATE + $i days" +"%Y-%m-%dT12:00:00")
	git add "$FILE_PATH"
	GIT_AUTHOR_DATE="$TARGET_DATE" GIT_COMMITTER_DATE="$TARGET_DATE" \
	git commit -m "DSA Day $DAY_NUM: Uploading $FILENAME"
done

git push origin main
