# EssayMarking
 
Letters with the corresponding points and types
 
![output3](https://user-images.githubusercontent.com/76905667/154759969-7cb5bda6-89dd-4401-bee0-828b7f20404e.png)

Criteria during the essay marking:
 
1.The shortest word should get between 10 and 50 points (count the points based on Table 1)(you should exclude one-letter words).

2.The longest word should get between 200 and 250 points.

3.There should be 5 or more different palindrome words in the essay (i.e. words reading thesame backward as forward, e.g. “stats”).

4.The length of the essay should be between 50 and 100 words.

5.The average number of letters used in a word should be between 4 and 8, and the average number of points (see Table 1) for the words used in the essay should be between 20 and 60.

6.It is not allowed to have words that have more than 4 letters of type V (find the type for each letter in Table 1).


There is a secret in the essay. The problem is that it’s enciphered with a key. So, these steps should be followed:

1.Calculate the key: the key for the essay is the remainder of dividing the number of points for student’s name (which is exactly the 10th word of the essay) by 26, e.g. if the 10th word is John (11 + 1 + 8 + 22 = 42), then the key is: 42 mod 26 = 16.

2.Find the secret: secret is the second word the number points (see Table 1) for which lies between 90 and 110. If there is no such a word, then the secret is the last word in the essay.

3.Decipher the secret: use the Caesar cipher and the key that you have already found to decipher the secret.


Tasks:

1.For each of the six criteria mentioned above, print out a statement of whether it passes or fails; you do not need to explain why, just print ‘pass’ or ‘fail’ for each criterion.

2.Print out the shortest word, the longest word, the word with the lowest number of points, the word with the highest number of points, the least frequent word and the most frequent word.

3.Print out the number of times each word appears in the essay in an ascending order.

4.Print out the student’s name, the key, the secret of the essay, and the deciphered version of the secret.

5.Sort all words by their points and print out the one in the middle (in case the number of words is even, concatenate the two in the middle and print them out as one word without any spaces in between)
