import requests
import sys
import json

courseId = "320100"
school = "byui"
single = "0";
num = 0

# Run the function
if len(sys.argv) > 2:
    school   = sys.argv[1]
    courseId = sys.argv[2]

# Load the JSON key file
with open('keys.json', 'r') as file:
    data = json.load(file)
    API_KEY = data[f"{school}"]
    # API_KEY = file.read()         # this is when I was just reading the file as a text file
    # API_KEY = API_KEY.rstrip("\r\n")

headers = { "Authorization": f"Bearer {API_KEY}" }

# Canvas API details
BASE_URL = f"https://{school}.instructure.com/api/v1"

def getStudents(courseId):
    """Fetch all students in the course."""
    students = []
    url = f"{BASE_URL}/courses/{courseId}/users"
    params = {
        "enrollment_type[]": "student",
        "per_page": 100,  # Maximum allowed per page
    }

    response = requests.get(url, headers=headers, params=params)
    students = response.json()
    return students

def getAssignments(courseId):
    """Fetch all assignments in the course."""
    assignments = []
    url = f"{BASE_URL}/courses/{courseId}/assignments"
    
    response = requests.get(url, headers=headers, params={"per_page": 100})
    assignments = response.json()
    return assignments

def getSubmissionByStatus(courseId, assignmentId, state):
    """Fetch the submission status of all students for a specific assignment."""
    submissions = []
    
    url = f"{BASE_URL}/courses/{courseId}/assignments/{assignmentId}/submissions"
    response = requests.get(url, headers=headers, params={"per_page": 100})
    submissions = response.json()
    
    # uniqueStates = {s['workflow_state'] for s in submissions}
    # print(uniqueStates)

    matchingState = [s for s in submissions if s['workflow_state'] == state]
    return matchingState

def listUnfinishedAssignments(courseId):
    """List students and their unsubmitted assignments."""
    students    = getStudents(courseId)
    assignments = getAssignments(courseId)
    studentAssignments = {student['id']: {"name": student['name'], "unsubmitted": []} for student in students}

    for assignment in assignments:
        submissions = getSubmissionByStatus(courseId, assignment['id'], 'unsubmitted')
        for submission in submissions:
            studentId = submission['user_id']
            if studentId in studentAssignments:
                studentAssignments[studentId]["unsubmitted"].append(assignment['name'])

    return studentAssignments

# Example usage:
unfinished_assignments = listUnfinishedAssignments(courseId)

# Display results
row = 0
for studentId, info in unfinished_assignments.items():
    row += 1
    print(f"Student: {row} {info['name']}")
    if info['unsubmitted']:
        print("  unSubmitted Assignments:")
        for assignment in info['unsubmitted']:
            print(f"    - {assignment}")
    else:
        print("  All assignments completed!")
    print()