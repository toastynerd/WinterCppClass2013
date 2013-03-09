#!/usr/bin/env perl                                                                                             

my $fileName=$ARGV[0];
my $searchStr=$ARGV[1];
my $replaceStr=$ARGV[2];

print ("\nFilename:",$fileName,"\n");
print ("Search String:",$searchStr,"\n");
print ("Replace String:",$replaceStr,"\n\n");

open(FILE,$fileName); 
my(@fcont) = <FILE>;
close FILE;

open(FOUT,">$fileName");
foreach $line (@fcont) {
    $line =~ s/$searchStr/$replaceStr/g;
    print FOUT $line;
}
close FOUT;