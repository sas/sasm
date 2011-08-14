#ifndef UTILS_BITOPS_H_
# define UTILS_BITOPS_H_

# define EXTRACT_BIT(Data, Index)           ((Data >> Index) & 1)
# define EXTRACT_BITRANGE(Data, Begin, End) ((Data & ((1 << (Begin + 1)) - 1)) >> End)

#endif /* !UTILS_BITOPS_H_ */
