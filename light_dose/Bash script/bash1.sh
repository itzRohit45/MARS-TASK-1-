#!/bin/bash

curr_dir=$PWD   #giving curr directory
echo "The current working directory is $curr_dir"

files=()

if [ -e $curr_dir/*.txt ]
then
for file in *.txt;do    #iterating for .txt extension file
     files+=("$file")    #appending in array if found
     echo "$file"       #displaying file name
 done

if [[ ${#files[@]} -gt 0 ]]    #if files found
then
  echo "Enter new directory name"     
  read dirname                      
   if [[ ! -d "$dirname" ]]          
then
     mkdir ./$dirname              #making new directory  if it not exists
for file in "${files[@]}"; do
     new_file="${file%.*}.bak"           #changing the extension
      cp "$file" "$dirname/$new_file"       #copying it into new directory
      done

fi
fi
else 
  echo "Files with .txt extension are not found in the current directory"
fi





