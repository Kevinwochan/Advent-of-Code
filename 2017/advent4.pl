#!/usr/bin/perl -w
use strict;

my $validPasswordPhrases = 0;

foreach my $line (<STDIN>){
	chomp($line);
	# track duplicates using a hash
	my %phrases= ();
	# match all words into a list
	my @words = split /\s+/, $line;
	# check each word for a hash collison
	# and add it to the hash
	$validPasswordPhrases++;
	foreach my $word (@words){
		if (exists $phrases{$word}){
			$validPasswordPhrases--;
			last;
		}else{
			$phrases{$word} = 1;
		}
	}
}

print "$validPasswordPhrases\n";
