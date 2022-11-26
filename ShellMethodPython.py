def shell_sort(arr):
    size = len(arr)
    gap = size // 2

    while gap > 0:
        for i in range(gap, size):
            anchor = arr[i]
            j = i
            while j >= gap and arr[j - gap] > anchor:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = anchor
        gap = gap // 2

if _name_ == '_main_':
    elements = [234,3334,1,1156,3422,12,9,12,1300]
    shell_sort(elements)
    print(elements)