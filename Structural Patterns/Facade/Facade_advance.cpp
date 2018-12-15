/*
 * C++ Design Patterns: Facade
 *
 * Provide a unified interface to a set of interfaces in a subsystem. Facade
 * defines a higher-level interface that makes the subsystem easier to use.
 * The pattern has structural purpose and applies to objects.
 *
 */

#include<iostream>

/*
 * ### When to use ###
 *
 * you want to provide a simple interface to a complex subsystem
 * there are many dependencies between clients and the implementation classes of an abstraction
 * you want to layer your subsystems, use a facade to define an entry point to each subsystem level
 *
 */

// Classes subsystems
#pragma region Subsystems

class MisDepartment
{
public:
	void submitNetworkRequest()
	{
		_state = 0;
	}
	bool checkOnStatus()
	{
		_state++;

		if (_state == States::Complete)
			return true;

		return false;
	}
	// ...

private:
	enum States
	{
		Received = 0,
		DenyAllKnowledge,
		ReferClientToFacilities,
		FacilitiesHasNotSentPaperwork,
		ElectricianIsNotDone,
		ElectricianDidItWrong,
		DispatchTechnician,
		SignedOff,
		DoesNotWork,
		FixElectriciansWiring,
		Complete
	};

	int _state;
};

class ElectricianUnion
{
public:
	void submitNetworkRequest()
	{
		_state = 0;
	}
	bool checkStatus()
	{
		_state++;

		if (_state == States::Complete)
			return true;

		return false;
	}
	// ...

private:
	enum States
	{
		Received = 0,
		RejectTheForm,
		SizeTheJob,
		SmokeAndJokeBreak,
		WaitForAuthorization,
		DoTheWrongJob,
		BlameTheEngineer,
		WaitToPunchOut,
		DoHalfAJob,
		ComplainToEngineer,
		GetClarification,
		CompleteTheJob,
		TurnInThePaperwork,
		Complete
	};

	int _state;
};

class FacilitiesDepartment
{
public:
	void submitNetworkRequest()
	{
		_state = 0;
	}
	bool checkStatus()
	{
		_state++;

		if (_state == States::Complete)
			return true;

		return false;
	}
	// ...

private:
	enum States
	{
		Received = 0,
		AssignToEngineer,
		EngineerResearches,
		RequestIsNotPossible,
		EngineerLeavesCompany,
		AssignToNewEngineer,
		NewEngineerResearches,
		ReassignEngineer,
		EngineerReturns,
		EngineerResearchesAgain,
		EngineerFillsOutPaperWork,
		Complete
	};

	int _state;
};

#pragma endregion

// Facade
class FacilitiesFacade
{
public:
	FacilitiesFacade() : _count(0)
	{}
	void submitNetworkRequest()
	{
		_state = 0;
	}
	bool checkOnStatus()
	{
		_count++;
		if (_state == States::Received)
		{
			_state++;
			_engineer.submitNetworkRequest();
			std::cout << "submitted to Facilities - " << _count << " phone calls so far" << std::endl;
			// ...
		}
		else if (_state == States::SubmitToEngineer)
		{
			if (_engineer.checkStatus())
			{
				_state++;
				_electrician.submitNetworkRequest();
				std::cout << "submitted to Electrician - " << _count << " phone calls so far" << std::endl;
				// ...
			}
		}
		else if (_state == States::SubmitToElectrician)
		{
			if (_electrician.checkStatus())
			{
				_state++;
				_technician.submitNetworkRequest();
				std::cout << "submitted to MIS - " << _count << " phone calls so far" << std::endl;
				// ...
			}
		}
		else if (_state == States::SubmitToTechnician)
		{
			if (_technician.checkOnStatus())
			{
				return true;
			}
		}

		return false;
	}
	int getNumberOfCalls()
	{
		return _count;
	}
	// ...

private:
	enum States
	{
		Received = 0,
		SubmitToEngineer,
		SubmitToElectrician,
		SubmitToTechnician
	};

	int _state;
	int _count;

	FacilitiesDepartment	_engineer;
	ElectricianUnion		_electrician;
	MisDepartment			_technician;
};


int main()
{
	FacilitiesFacade facilities;

	facilities.submitNetworkRequest();
	while (!facilities.checkOnStatus());

	std::cout << "job completed after only " << facilities.getNumberOfCalls() << " phone calls" << std::endl;
	// ...

	return 0;
}
