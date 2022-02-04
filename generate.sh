awk 'NR==FNR{a[$0];next} !($0 in a) ' $1 $2 | sort | uniq
