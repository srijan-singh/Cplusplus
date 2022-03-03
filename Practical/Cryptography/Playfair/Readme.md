# Playfair Cipher

The Playfair cipher was the first practical digraph substitution cipher. The scheme was invented in 1854 by Charles Wheatstone but was named after Lord Playfair who promoted the use of the cipher. In playfair cipher unlike traditional cipher we encrypt a pair of alphabets(digraphs) instead of a single alphabet.

## The Playfair Cipher Encryption Algorithm: 

### The Algorithm consists of 2 steps: 
 

1. **Generate the key Square(5×5):**
    - The key square is a 5×5 grid of alphabets that acts as the key for encrypting the plaintext. Each of the 25 alphabets must be unique and one letter of the alphabet (usually J) is omitted from the table (as the table can hold only 25 alphabets). If the plaintext contains Z, then it is replaced by Y. 
 
    - The initial alphabets in the key square are the unique alphabets of the key in the order in which they appear followed by the remaining letters of the alphabet in order. 
 
2. **Algorithm to encrypt the plain text:** The plaintext is split into pairs of two letters (digraphs). If there is an odd number of letters, a X is added to the last letter. 
For example: 
 
        PlainText: "instruments" 
        After Split: 'in' 'st' 'ru' 'me' 'nt' 'sx'

### Example

1. Pair cannot be made with same letter. Break the letter in single and add a bogus letter to the previous letter.

        Plain Text: “hello”

        After Split: ‘he’ ‘lx’ ‘lo’

Here *‘x’* is the bogus letter.

2. If the letter is standing alone in the process of pairing, then add an extra bogus letter with the alone letter

        Plain Text: “helloe”

        After Split: ‘he’ ‘lx’ ‘lo’ ‘ex’

Here *‘x’* is the bogus letter.

## Rules for Encryption: 
 

- **If both the letters are in the same column:** Take the letter below each one (going back to the top if at the bottom).
For example: 
 
        Diagraph: "me"
        Encrypted Text: cl
        Encryption: 
        m -> c
        e -> l

 
- **If both the letters are in the same row:** Take the letter to the right of each one (going back to the leftmost if at the rightmost position).
For example: 
 
        Diagraph: "st"
        Encrypted Text: tl
        Encryption: 
        s -> t
        t -> l

 
- **If neither of the above rules is true:** Form a rectangle with the two letters and take the letters on the horizontal opposite corner of the rectangle.

**For example:** 
 
    Diagraph: "nt"
    Encrypted Text: rq
    Encryption: 
    n -> r
    t -> q
