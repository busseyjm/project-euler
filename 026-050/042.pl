# Coded triangle numbers
 
# Problem 42

# The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); 
#   so the first ten triangle numbers are:

# 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

# By converting each letter in a word to a number corresponding to its alphabetical 
#   position and adding these values we form a word value. For example, the word 
#   value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number 
#   then we shall call the word a triangle word.

# Using words.txt (right click and 'Save Link/Target As...'), a 16K text file 
#   containing nearly two-thousand common English words, how many are triangle words?


#!/usr/bin/perl

use strict;
use warnings;

my $file = "./042.txt";
my @words;
my @triangles;

# populate the triangle list, im using 50 values of n
#   but i'll bet fewer can be used
for (my $i=1; $i<50; $i++) {
  push(@triangles, .5*$i*($i+1));
}

# pass a word, split the word into letters and work out the value
#  return 1 if it's triangle, 0 if not
sub triangle {

  my $word = $_[0];
  my $score= 0;
  my @letters = split('', $word);

  # find the value of each letter and add it to the score
  #   A = 1, Z=26
  foreach my $char (@letters) {
    #force uppercase for accurate ascii values
    $char = uc $char;

    # ord finds numeric value of a letter
    # subtract 64 from letters so A corresponds to 1

    # print (ord($char)-64 . "\n");
    $score += ord($char) - 64;
  }

  if ($score ~~ @triangles) {
    #print "$word is a triangle, value: $score\n";
    return 1;
  }

  return 0;
  #return $score*($rank+1);
}



# this only works because the words are on one line, otherwise will
#   run per line
open (INPUT, $file)     || die "can't open $file: $!";
while (<INPUT>) {
  chomp;
  
  # remove first and last chars (trailing "s)
  substr($_, 0, 1) = ''; 
  chop($_);

  # split on "," (hacky, but works)
  @words = split("\",\"", $_);
}
close(INPUT)            || die "can't close $file: $!";


my $trianglecount = 0;

for (my $i=0; $i<scalar(@words); $i++) {
  # print "$i\t$names[$i]\t" . score($i, $names[$i]) . "\n";
  $trianglecount += triangle($words[$i]);
}

print $trianglecount . "\n";

