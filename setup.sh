#! /bin/sh

peterFolder="Peter"
madelineFolder="Madeline"
notesFolder="Notes"

for currTextFile in misc/textfiles/*
do
  (
  #echo "$currTextFile"
  file="${currTextFile%.txt}"
  #echo "$file"
  file="${file##*/}"
  #echo "$file"
  mkdir "$file"
  mv "$currTextFile" "$file/README.md"
  cd "$file" || exit
  mkdir $peterFolder
  mkdir $madelineFolder
  mkdir $notesFolder
  cd ..
  )
done
