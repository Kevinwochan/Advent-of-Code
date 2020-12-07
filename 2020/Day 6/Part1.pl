#!/usr/bin/perl
use strict;
use warnings;

use autodie;
use Path::Tiny;

my $content = path("input.txt")->slurp_utf8;
$content = join(", ",split(/\n\n/, $content));
$content =~ s/\n//g;
my @lines = split(/, /, $content);
my $count = 0;
foreach (<@lines>){
    my $unique_letters = 0;
    my %is_unique;
    foreach my $char (split//, $_) {
        if (!exists($is_unique{$char})){
            $is_unique{$char} = 1;
            $unique_letters++;
        }
    }
    $count += $unique_letters;
}

print $count;

