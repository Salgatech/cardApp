# 27/05/23 SAG Small script to validate the shuffle function.

from difflib import Differ

count = 0

with open("diagsBefore.txt") as Diags_Before, open("diagsAfter.txt") as Diags_Ater:
  differ = Differ()
  count = count + 1
  if count > 3 :
    line_in_before = Diags_Before.readline()
    line_in_after  = Diags_After.readline()
    
