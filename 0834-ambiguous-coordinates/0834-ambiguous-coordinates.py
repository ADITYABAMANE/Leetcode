class Solution(object):
    def ambiguousCoordinates(self, s):
        def valid_numbers(s):
            if s == "0" or (s[0] != "0" or len(s) == 1):
                yield s
            if s[0] == "0" and len(s) > 1 and s[-1] != "0":
                yield "0." + s[1:]
            if s[0] != "0":
                for i in range(1, len(s)):
                    if s[-1] != "0":
                        yield s[:i] + "." + s[i:]

        s = s[1:-1]
        result = []
        for i in range(1, len(s)):
            left_parts = list(valid_numbers(s[:i]))
            right_parts = list(valid_numbers(s[i:]))
            for left in left_parts:
                for right in right_parts:
                    result.append("({}, {})".format(left, right))
        return result