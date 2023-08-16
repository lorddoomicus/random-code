#!/bin/bash
#
# (c) 2020 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2020-11-20	dwalker		Initial Version

  
infile="$1"
outfile=$( basename -s .m4v "$infile" ).mp4

ffmpeg -i "$infile" -vcodec copy -acodec copy "$outfile"
