# CPP
#### **Exercises 1 :**
Ask a user to enter an integer and displays the average of the digits in the integer. For example, the 
average of the digits in 936 is 6.0 ((9 + 3 + 6) / 3).<br>
Output:<br>
```{r}
Enter numer : 1231245
The average of the digits in 1231245 is 2.57143
```
#### **Exercises 2 :**
A number is a palindrome if its reversal is the same as itself. An even palindrome number is a number 
which is even and also a palindrome. Write a program that displays the first 50  positive even 
palindrome numbers ten per line.
Output:<br>
```{r}
0       2       4       6       8       22      44      66      88      202
212     222     232     242     252     262     272     282     292     404
414     424     434     444     454     464     474     484     494     606
616     626     636     646     656     666     676     686     696     808
818     828     838     848     858     868     878     888     898     2002
```
#### **Exercises 3 :**
(Check Valid Password) Some websites impose certain rules for passwords. Suppose the rules are as 
follows:<br>
• A password must have exactly 8 characters.<br>
• A password must consist of only digits and letters.<br>
• A password must always start with a digit.<br>
• A password must contain at least one uppercase letter.<br>
Write a program that asks a user to enter a password and displays if the password entered is valid or 
invalid. If it is invalid, let the user know why.<br>
Output:<br>
```{r}
Enter your password : 23Phanith
 Passed Test 1 : ✅
 Passed Test 2 : ✅
 Passed Test 3 : ✅
 Passed Test 4 : ✅
 Passed Final Test : ✅
 Valid Password
```
```{r}
Enter your password : 1232asd 
 Failed Test 1 : ❌
 Failed Final Test : ❌
 Valid Password
```
#### **Exercises 4 :**
<p>(Game: locker puzzle) In the first game of the Squid Game, there are 456 lockers and 456 players. 
Each player has to pick one locker number, then enters a builder. When the game starts, all the 
lockers are closed. As the players enter the building, the first player (P1) has to open every locker. 
Then the second player (P2) begins with the second locker (L2), and has to close every other locker 
(L2 to L456). Player P3 begins with the third locker (L3) and has to change (closes the locker if it was 
open, and open it if it was closed) every third locker (L3, L6, …). Player P4 begins with locker L4 
and changes every fourth locker (L4, L8, …). Player P5 starts with L5 and changes every fifth locker (L5, L10, …), and so on, until Player P456 changes L456.</p><br>
<p>After all the players have passed through the building and changed the lockers, the game ends. The players whose locker closed will be killed.</p><br>

<p>Write a program to display all open locker numbers separated by exactly one space and ten per line. 
How many open lockers in total? (Hint: Use an array of 456 bool elements, each of which indicates 
whether a locker is open (true) or closed (false).)</p><br>
Output:<br>

```{r}
Locker Puzzle : Squid Game
1       4       9       16      25      36      49      64      81      100
121     144     169     196     225     256     289     324     361     400
441

Opened : 21
Closed : 435
```