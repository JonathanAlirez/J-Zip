# J-Zip
zipping application using C++ to condense large files

# Steps to achieve turning a file into a 'jzip' file
1.) Read the file and make a custom vector of every word that is in the file. (word, wordCount); <br />
2.) Sort the vector in descending order. <br />
3.) Write to a new file, .jzip, the vector with a custom id (word : id \n word : id <br />
4.) Next, read the original file and replace any word that is on the list, with the custom id <br />
<br/ >
# Steps to unzip a 'jzip' file into a txt file
1.) Read the jzip file header and put the word and custom id into a custom vector (word, customId) <br/ >
2.) read the jzip file and write to a new file, .txt, and anytime a id is read on a line, replace the id with the word that it is associated with. <br />
<br />
# Considerations for further implementations
In order to further this applications use, it would have to be able to zip more effectively. Right now, this application only looks at word frequency, maybe looking to removing whitespaces might be something to help make the jzip file smaller. If all things are created equal here are some rough estimates of how effective J-Zip is compared to Windows Zip

# Estimates
Windows Zip<br/ >
583 kb -> 222kb (REAL)<br/ >
1 gb -> .38 gb (ESTIMATE)<br/ >
<br /> 
J-Zip<br/ >
583kb -> 502kb<br />
1 gb -> .86 gb (ESTIMATE)<br />
