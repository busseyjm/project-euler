# Names scores
 
# Problem 22

# Using names.txt (right click and 'Save Link/Target As...'), 
#   a 46K text file containing over five-thousand first names, 
#   begin by sorting it into alphabetical order. Then working 
#   out the alphabetical value for each name, multiply this value 
#   by its alphabetical position in the list to obtain a name score.

# For example, when the list is sorted into alphabetical order, COLIN, 
#   which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the 
#   list. So, COLIN would obtain a score of 938 × 53 = 49714.

# What is the total of all the name scores in the file?

#!/usr/bin/perl

use strict;
use warnings;

my $file = "./022.txt";
my @names;

# pass a words alphabetical rank and the word
#   split the word into letters and work out the score
sub score {

  my $rank = $_[0];
  my $word = $_[1];
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

  return $score*($rank+1);
}



# this only works because the names are on one line, otherwise will
#   run per line
open (INPUT, $file)     || die "can't open $file: $!";
while (<INPUT>) {
  chomp;
  
  # remove first and last chars (trailing "s)
  substr($_, 0, 1) = ''; 
  chop($_);

  # split on "," (hacky, but works)
  @names = split("\",\"", $_);
}
close(INPUT)            || die "can't close $file: $!";

# alphabetically sort names array
@names = sort(@names);

my $scoresum = 0;

for (my $i=0; $i<scalar(@names); $i++) {
  # print "$i\t$names[$i]\t" . score($i, $names[$i]) . "\n";
  $scoresum += score($i, $names[$i]);
}

print $scoresum . "\n";

