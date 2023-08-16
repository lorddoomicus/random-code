#!/bin/bash
#
# Makes an index of tiff files uploaded to s3
#
# This could be easily adapted to use any file type such as pdf, jpgs or even doc files
#
# (c) 2022 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2022-08-06	dwalker		Initial Version

# These variables have to be set to your S3 bucket and URL
s3_uri="s3://spacy-web/special/scanned-tiffs/"
s3_url="https://spacy-web.s3.amazonaws.com/special/scanned-tiffs/"

tmp=$( mktemp )
listing=$( mktemp )

# Header
echo '<head><title>The TIFF Files</title></head>' > $tmp
echo '<body>' >> $tmp
echo '<B>NOTE:</B> These will be removed after 60 days from the indicated upload date<p>' >> $tmp

aws s3 ls $s3_uri | grep .tif > $listing

# Lines
while read line
do
	tif=$( echo $line | awk '{print $NF }' )

	href="<a href=\"${s3_url}$tif\">${tif}</a><br>"
	# echo $line
	# echo $tif
	# echo $href
	echo $line | sed "s%scan.*%$href%" >> $tmp

done < $listing

# Footer
echo "</body>" >> $tmp
echo "</html>" >> $tmp

# cleanup
mv $tmp index.html
rm $listing	

# upload index.html
aws s3 cp index.html $s3_uri
