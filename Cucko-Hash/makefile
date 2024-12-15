CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lm

# Automatically find all C source files in the directory
SRCS = $(wildcard *.c)
# Generate object files for each source file
OBJS = $(SRCS:.c=.o)

# Define the target executable
TARGET = myht 

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile each .c file to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)