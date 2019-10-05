
import array 
"""" Quick Sort implementation as done in CLRS """

def quicksort(arr,first,last):
    if first<last:
        middle = partition(arr,first,last)
        quicksort(arr,first,middle-1)
        quicksort(arr,middle+1,last)

def partition(arr,first,last):

    """ Taking last element as Pivot """
    pivot = arr[last]
    """ zone for elements smaller than pivot """
    zone_index = first-1    
    for j in range(first,last):
        if arr[j] <= pivot :
            zone_index += 1
            arr[j], arr[zone_index] = arr[zone_index], arr[j]
    
    
    arr[last] = arr[zone_index+1] 
    arr[zone_index+1] = pivot

    return zone_index+1


arr = array.array('i',[9,8,7,6,5,4,3,2,1])
quicksort(arr,0,len(arr)-1)
print(arr)

    


 