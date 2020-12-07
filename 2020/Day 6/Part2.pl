#!/usr/bin/perl
use strict;
use warnings;

use autodie;
use Path::Tiny;

my $content = path("input.txt")->slurp_utf8;
$content = join(", ",split(/\n\n/, $content));
$content =~ s/\n/,/g;
my @lines = split(/, /, $content);
my $count = 0;
# For each group
foreach (<@lines>){
    my $person_count = 0;
    my %answer_count;
    # Find out how many members in a group
    print "=== New Group ===\n";
    
    # For each person, iterate over the person's answers
    foreach my $answer (split /,/, $_) {
        printf "P%d: %s\n", $person_count, $answer;
        # Add all answers to the hashtable of questions
        foreach my $char (split//, $answer) {
            if (!exists($answer_count{$char})){
                $answer_count{$char} = 0;
            }
            $answer_count{$char}++;
        }
        $person_count++;
    }
    foreach my $value (values %answer_count){
        print $value, " : ", $person_count, "\n";
        if ($value == $person_count){
            $count++;
        }
    }
}

print $count;
